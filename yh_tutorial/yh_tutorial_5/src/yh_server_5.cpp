#include "ros/ros.h"
#include "yh_tutorial_5/yh_srv_5.h"

bool srvCallback(yh_tutorial_5::yh_srv_5::Request &req, yh_tutorial_5::yh_srv_5::Response &res)
{
    res.result = req.a * req.b;

    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "yh_server_5");
    ros::NodeHandle nh;

    ros::ServiceServer service_server = nh.advertiseService("yh_service_5", srvCallback);

    ROS_INFO("Service server ready.");

    ros::spin();

    return 0;
}


