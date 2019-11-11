/**Copyright (c) 2019 Jing Liang
 * @file       test.cpp
 * @date       11/10/2019
 * @brief      This file is the test file of rostest
 * @license    This project is released under the BSD-3-Clause License.
 */
#include <gtest/gtest.h>
#include <tf/transform_listener.h>
#include <std_msgs/String.h>
#include <boost/bind.hpp>


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
    try {
      listener.lookupTransform("/world", "/talk", ros::Time(0), transform);
      if (transform.getOrigin() == tf::Vector3(1, 0, 0) &&
        transform.getRotation() == quaternionValue) {
        test = true;
      }
    }
    catch (tf::TransformException ex) {
      ROS_INFO("%s", ex.what());
    }
  }

  EXPECT_EQ(groundtruth, test);
}

/** @brief class can define subscriber and save subscribed data */
class testPublisher {
 public:
  /** @brief received message. */
  std::string message;

  /** @brief ros node handle. */
  ros::NodeHandle n;

  /** @brief subscriber of chatter topic. */
  ros::Subscriber sub;

  /**
   * @brief define subscriber
   */
  void defineSubscriber();

  /**
   * @brief call back function print message when received it
   * @param message of chatter
   */
  void chatterCallback(const std_msgs::String::ConstPtr& msg);
};

void testPublisher::defineSubscriber() {
  testPublisher::sub = n.subscribe<std_msgs::String>("chatter", 10,
    &testPublisher::chatterCallback, this);
}

void testPublisher::chatterCallback(const std_msgs::String::ConstPtr& msg) {
  testPublisher::message = msg->data;
}

/**
 * @brief Checks if publish message is right
 */
TEST(testPublish, should_pass) {
  testPublisher testing;
  testing.defineSubscriber();

  std::string groundtruth = "It's a customized message";

  while (testing.message == "")  ros::spinOnce();

  EXPECT_EQ(groundtruth, testing.message);
}
