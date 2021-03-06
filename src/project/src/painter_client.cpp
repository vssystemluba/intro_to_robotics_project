#include "ros/ros.h"
#include "project/painter.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "painter_client");
  if (argc != 2)
  {
    ROS_INFO("usage: painter_client /path/to/vector/image");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<project::painter>("painter");
  project::painter srv;
  srv.request.filePath = argv[1];
  ROS_INFO("argv[1]: %s", argv[1]);
  if (client.call(srv))
  {
    ROS_INFO("Returned: %u", srv.response.returnStatus);
  }
  else
  {
    ROS_ERROR("Failed to call painter service.");
    return 1;
  }

  return 0;
}
