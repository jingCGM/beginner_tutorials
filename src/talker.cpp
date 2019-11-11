/**Copyright (c) 2019 Jing Liang
 * @file       talker.cpp
 * @date       10/26/2019
 * @brief      The file defined publisher, which publish "chatter" topic
 * @license    This project is released under the BSD-3-Clause License.
 */
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <tf/transform_broadcaster.h>
#include <cstdlib>
#include <sstream>


/**
 * @brief main function of subscriber, which publish "chatter" topic
 * @param **argv arguments value
 * @param argc arguments
 * @return 0
 */
int main(int argc, char **argv) {
  ros::init(argc, argv, "talker");


  tf::TransformBroadcaster broadcaster;
  tf::Transform transform;
  transform.setOrigin(tf::Vector3(1, 0, 0));
  tf::Quaternion quaternionValue;
  quaternionValue.setRPY(0, 0, 1.57);
  transform.setRotation(quaternionValue);

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  int looprate = 0;

  if (argc != 2) {
    ROS_WARN_STREAM("default loop rate is 10");
    looprate = 10;
  } else {
    looprate = atoi(argv[1]);
  }

  if (looprate < 1) looprate = 1;
  else if (looprate > 20) looprate = 20;

  ROS_DEBUG_STREAM("rate: " << looprate);
  ros::Rate loop_rate(looprate);

  while (ros::ok()) {
    std_msgs::String msg;
    std::stringstream ss;
    ss << "It's a customized message";
    msg.data = ss.str();

    broadcaster.sendTransform(tf::StampedTransform(transform,
      ros::Time::now(), "world", "talk"));

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
