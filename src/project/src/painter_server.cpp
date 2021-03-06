#include "ros/ros.h"
#include "project/painter.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool paint(project::painter::Request &req,
           project::painter::Response &res)
{
  const char* filePath = req.filePath.c_str();
  res.returnStatus = 5;
  ROS_INFO("request: '%s'", filePath);

  /*
	Code to process .svg image and create and publish commands
  */

	std::string line;
	std::ifstream infile(filePath);
	while(std::getline(infile, line)){
		cout << line << endl;
	}
	infile.close();

  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "painter_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("painter", paint);
  ROS_INFO("Ready to paint.");
  ros::spin();

  return 0;
}
