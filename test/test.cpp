/**Copyright (c) 2019 Jing Liang
 * @file       test.cpp
 * @date       11/10/2019
 * @brief      This file is the test file of rostest
 * @license    This project is released under the BSD-3-Clause License.
 */
#include <gtest/gtest.h>
#include <tf/transform_listener.h>
#include <std_msgs/String.h>

// global variable which is used to store subscribed value 
static std::string message;


/**
 * @brief Checks if tf frames are right
 */
TEST(testTF, should_pass) {
  ros::NodeHandle nh;
  tf::TransformListener listener;

  tf::StampedTransform transform;

  bool test = false;
  bool groundtruth = true;

  tf::Quaternion quaternionValue;
  quaternionValue.setRPY(0, 0, 1.57);

  while (!test) {
    try{
      listener.lookupTransform("/world", "/talk", ros::Time(0), transform);
      if ( transform.getOrigin() == tf::Vector3(1,0,0) && transform.getRotation() == quaternionValue) {
	  	test = true;
	  }
    }
    catch (tf::TransformException ex){
      ROS_INFO("%s",ex.what());
    }
  }

  EXPECT_EQ(groundtruth, test);
}


/**
 * @brief call back function check message when received it
 * @param message of chatter
 */
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
  message = msg->data;
}


/**
 * @brief Checks if publish message is right
 */
TEST(testPublish, should_pass) {
  ros::NodeHandle nh1;
  
  ros::Subscriber sub = nh1.subscribe("chatter", 1000, chatterCallback);

  std::string groundtruth = "It's a customized message";

  while (message == "")  ros::spinOnce();

  EXPECT_EQ(groundtruth, message);
}