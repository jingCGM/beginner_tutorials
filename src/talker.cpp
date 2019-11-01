/**Copyright (c) 2019 Jing Liang
 * @file       talker.cpp
 * @date       10/26/2019
 * @brief      The file defined publisher, which publish "chatter" topic
 * @license    This project is released under the BSD-3-Clause License.
 */
#include <cstdlib>
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * @brief main function of subscriber, which publish "chatter" topic
 * @param **argv arguments value
 * @param argc arguments
 * @return 0
 */
int main(int argc, char **argv) {
  ros::init(argc, argv, "talker");

  if (argc != 2) {
    ROS_FATAL_STREAM("please set loop rate");
    return 1;
  }

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  int looprate = atoi(argv[1]);
  if (looprate<1) looprate = 1;
  else if(looprate>20) looprate = 20;

  ROS_DEBUG_STREAM("rate: "<<looprate);
  ros::Rate loop_rate(looprate);

  int count = 0;
  while (ros::ok()) {
    std_msgs::String msg;

    std::stringstream ss;
    ss << "It's a customized message: " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
