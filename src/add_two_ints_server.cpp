/**Copyright (c) 2019 Jing Liang
 * @file       add_two_ints_server.cpp
 * @date       10/26/2019
 * @brief      The file defined client of server, which apply add function
 * @license    This project is released under the BSD-3-Clause License.
 */
#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"

/**
 * @brief service callback function which apply add function
 * @param request values
 * @param response value
 * @return true
 */
bool add(beginner_tutorials::AddTwoInts::Request  &req,
         beginner_tutorials::AddTwoInts::Response &res) {
  res.sum = req.a + req.b;
  ROS_INFO_STREAM("request: x="<<(int64_t)req.a<<", y="<<(int64_t)req.b);
  ROS_INFO_STREAM("sending back response: "<<(int64_t)res.sum);

  ROS_DEBUG_STREAM("testing debug logging");
  ROS_INFO_STREAM("testing info logging");
  ROS_WARN_STREAM("testing warning logging");
  ROS_ERROR_STREAM("testing error logging");
  ROS_FATAL_STREAM("testing fatal logging");
  
  return true;
}

/**
 * @brief main function of client, which apply service of add function
 * @param **argv arguments value
 * @param argc arguments
 * @return 0
 */
int main(int argc, char **argv) {
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("add_two_ints", add);
  ROS_INFO_STREAM("Ready to add two ints.");
  ros::spin();

  return 0;
}
