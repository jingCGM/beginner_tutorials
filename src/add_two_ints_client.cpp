/**Copyright (c) 2019 Jing Liang
 * @file       add_two_ints_client.cpp
 * @date       10/26/2019
 * @brief      The file defined client of server, which ask add function
 * @license    This project is released under the BSD-3-Clause License.
 */
#include <cstdlib>
#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"


/**
 * @brief main function of client, which ask add function
 * @param **argv arguments value
 * @param argc arguments
 * @return 1 if there is error, 0 if ok.
 */
int main(int argc, char **argv) {
  ros::init(argc, argv, "add_two_ints_client");
  if (argc != 3) {
    ROS_INFO_STREAM("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts\
    >("add_two_ints");
  beginner_tutorials::AddTwoInts srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  if (client.call(srv)) {
    ROS_INFO_STREAM("Sum: "<<(int64_t)srv.response.sum);
  } else {
    ROS_ERROR_STREAM("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
