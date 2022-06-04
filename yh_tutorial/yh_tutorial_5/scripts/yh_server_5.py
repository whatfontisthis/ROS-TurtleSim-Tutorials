#!/usr/bin/python
# -*- coding: utf8 -*-

import rospy
from yh_tutorial_5.srv import yh_srv_5, yh_srv_5Response

def srvCallback(req):
    return yh_srv_5Response(req.a * req.b)

def yh_server():
    rospy.init_node("yh_server_5")
    service_server = rospy.Service("yh_service_5", yh_srv_5, srvCallback)
    rospy.spin()

if __name__ == "__main__":
    yh_server()