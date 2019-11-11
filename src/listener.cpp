/**Copyright (c) 2019 Jing Liang
 * @file       listener.cpp
 * @date       10/26/2019
 * @brief      The file defined subscriber, which subscribe "chatter" topic
 * @license    This project is released under the BSD-3-Clause License.
 */
#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * @brief call back function print message when received it
 * @param message of chatter
 */
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO_STREAM("I heard: "<< msg->data);
}

/**
 * @brief main function of subscriber, which subscribe "chatter" topic
 * @param **argv arguments value
 * @param argc arguments
 * @return 0
 */
int main(int argc, char **argv) {
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  ros::spin();

  return 0;
}
