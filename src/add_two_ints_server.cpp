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
  ROS_INFO("request: x=%ld, y=%ld", (int64_t)req.a, (int64_t)req.b);
  ROS_INFO("sending back response: [%ld]", (int64_t)res.sum);
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
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}
