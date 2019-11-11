/**Copyright (c) 2019 Jing Liang
 * @file       main.cpp
 * @date       11/10/2019
 * @brief      This file is the main file of rostest
 * @license    This project is released under the BSD-3-Clause License.
 */
#include <gtest/gtest.h>
#include <ros/ros.h>


/**
 * @brief  main function for rostest
 * @param  argc int
 * @param  argv arguments value
 * @return 0
 */
int main(int argc, char** argv) {
  ros::init(argc, argv, "rosTest");
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
