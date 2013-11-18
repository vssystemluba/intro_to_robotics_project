#!/usr/bin/env python  
from project.srv import *
import roslib
import rospy
import tf
from svg.src.svg.path import parse_path, Path, Line, QuadraticBezier

def handle_paint(req):
	status = 0
	print "Heard "+req.filePath
	file = open(req.filePath, 'r')
	print "File contents:  "+file.read()
	return status

def painter_server():
    rospy.init_node('painter_server')
    s = rospy.Service('painter_service', painter, handle_paint)
    print "Ready to do stuff."
    rospy.spin()

if __name__ == "__main__":
    painter_server()
