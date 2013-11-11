#!/usr/bin/env python  
from project.srv import *
import roslib
import rospy
import tf

def handle_paint(req):
    print "Heard " + req.filePath
    return painterResponse(0)

def painter_server():
    rospy.init_node('painter_server')
    s = rospy.Service('painter_service', painter, handle_paint)
    print "Ready to do stuff."
    rospy.spin()

if __name__ == "__main__":
    painter_server()
