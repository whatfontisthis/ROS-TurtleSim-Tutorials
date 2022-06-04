#include "ros/ros.h"
#include "yh_tutorial_5/yh_srv_5.h"
#include <cstdlib>

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "yh_client_5");

    if (argc != 3)
    {
        ROS_INFO("wrong command");
        return 1;
    }

    ros::NodeHandle nh;

    ros::ServiceClient service_client = nh.serviceClient<yh_tutorial_5::yh_srv_5>("yh_service_5");

    yh_tutorial_5::yh_srv_5 srv;

    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);

    if (service_client.call(srv))
    {
        ROS_INFO("%ld", srv.response.result);
    }
    else
    {
        ROS_ERROR("Failed");
        return 1;
    }

    return 0;
}