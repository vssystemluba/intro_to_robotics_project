#!/usr/bin/env python  
from project.srv import *
import roslib
import rospy
import tf
import re
from svg.src.svg.path import parse_path, Path, Line, QuadraticBezier

#global step size to use for generating points
stepSize = 0.5

#list in which to store all of our generated 3D points
pointList = []

#variables to use to check and see if we have to lift the pen between two paths in SVG file
lastEndx = -1
lastEndy = -1
firstPathFlag = True

def handle_paint(req):
	global pointList
	status = 0
	print "Heard "+req.filePath
	#open file and read contents	
	try:
		f = open(req.filePath, 'r')
		fileContents = f.readlines()
		f.close()
	except:
		print "Failed to read contents of file "+req.filePath
		return 1
	#print fileContents
	pathFlag = False
	foundDFlag = False
	for line in fileContents:
		if "<path" in line:
			pathFlag = True
		if pathFlag:
			if" d=" in line:
				foundDFlag = True	
				#strip off extra stuff and only grab the d	
				path = re.sub(".*?(d=)", "\\1", line, 1)
				patharray = path.split('"')
				#print "path: "+patharray[1]
				parsedPath = parse_path(path)
				#print parsedPath
				#Then, do things with our parsed SVG path:
				handleParsedPath(parsedPath)
	#exit and return an error if we couldn't find a path
	if not pathFlag or not foundDFlag:
		print "Failed to parse contents of file "+req.filePath
		return 2
	
	for point in pointList:
		print point
	return status

def painter_server():
    rospy.init_node('painter_server')
    s = rospy.Service('painter_service', painter, handle_paint)
    print "Ready to do stuff."
    rospy.spin()

def handleParsedPath(parsedPath):
	global pointList
	global firstPathFlag
	global lastEndx
	global lastEndy
	for i in range(0, len(parsedPath)):
		#check if we're starting a line segment from somewhere other than our last segment's end point
		startx = parsedPath[i].point(0.0).real
		starty = parsedPath[i].point(0.0).imag
		if not firstPathFlag and ((startx != lastEndx) or (starty != lastEndy)): 
			#code to handle pen jumps
			penJump(lastEndx, lastEndy, startx, starty)
		#print "Path: "+str(parsedPath[i])
		#print "Length: "+str(parsedPath[i].length())
		#calculate a relative step size for each path segment based on its total length and the global step size
		relativeStepSize = parsedPath[i].length() / stepSize
		#if relativeStepSize is 0, the path is trying to cheat and draw a point using a line of length 0:
		if relativeStepSize == 0:
			pointList.append(str(parsedPath[i].point(0.0).real)+","+str(parsedPath[i].point(0.0).imag)+",0")
		else:
			j = 0.0
			while j < 1.0:
				#print str(parsedPath[i].point(j).real)+", "+str(parsedPath[i].point(j).imag)+", 0)"
				pointList.append(str(parsedPath[i].point(j).real)+","+str(parsedPath[i].point(j).imag)+",0")
				j += 1.0 / relativeStepSize	
			#have to manually handle the end point since the step size probably won't hit it exactly
			lastEndx = parsedPath[i].point(1.0).real
			lastEndy = parsedPath[i].point(1.0).imag
			#print str(parsedPath[i].point(1.0).real)+", "+str(parsedPath[i].point(1.0).imag)+", 0)"
			pointList.append(str(parsedPath[i].point(1.0).real)+","+str(parsedPath[i].point(1.0).imag)+",0")
		firstPathFlag = False

#this function generates path points for pen jumps from the point (lastEndx, lastEndy) to the point (startx, starty).
def penJump(lastEndx, lastEndy, startx, starty):
	global pointList
	#print "PEN JUMP FROM ("+str(lastEndx)+", "+str(lastEndy)+") to ("+str(startx)+", "+str(starty)+")"
	z = 0
	while z >= -10:
		pointList.append(str(lastEndx)+","+str(lastEndy)+","+str(z))
		z -= 1
	for i in range(0, 99):
		pointList.append(str(lastEndx + i*(startx-lastEndx)/100)+","+str(lastEndy + i*(starty-lastEndy)/100)+","+str(z))
	while z <= 0:
		pointList.append(str(startx)+","+str(starty)+","+str(z))
		z += 1
	

if __name__ == "__main__":
    painter_server()
