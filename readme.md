# beginner_tutorials
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
---
## Overview
beginner_tutorials is a project followed ROS tutorials, the project contains communicating string message by publisher and subscriber functions and also add operation by server and client function.

## assumptions
system is Ubuntu 16.04;

## dependencies
```
ROS Kinetic
c++ 11
```

## Build Instructions
For new work space
```
cd ~
mkdir catkin_ws
cd catkin_ws
mkdir src
cd src
git clone https://github.com/jingCGM/beginner_tutorials.git
cd beginner_tutorials
git checkout Week11_HW
cd ../../
catkin_make
echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
```
---
If there exist beginner_tutorials project
```
roscd beginner_tutorials
git pull
git checkout Week11_HW
cd ../../
catkin_make
```

## Run launch files:
Run publisher and subscriber: open terminal: Where user can change value of rate. In extra terminals, there will be talker and listeners information. default value is 2, and the range of rate is from 1 to 20, if user set value out of the range, code will use nearest values available in the range. 
```
	roslaunch beginner_tutorials topics.launch rate:=1 record:=false
```

---
Run server and client: open terminal: Where user can change values of value1 and value2. In extra terminal, there will be sum of the two values. Dedault value of value1 and value2 are 1 and 2. Terminal also shows testing messages of all 5 loggings.
```
	roslaunch beginner_tutorials services.launch value1:=0 value2:=1
```


## Run recorder:
recorder will record rosbag in 15 seconds and save it in results folder. record argument can control if save ros bag, and its default value is false. default publishing rate is 10hz. If you want to run launch file without recording, please refer to section "Run launch files"
```
	roslaunch beginner_tutorials topics.launch record:=true
```

After record finished terminal will show: "[record-4] process has finished cleanly". Then stop the current terminal using Ctrl+c.

To test the bag file do following commands:
```
	roscore
```
in new terminal, run:
```
	rosrun beginner_tutorials listener
```
in new terminal, run:
```
	roscd beginner_tutorials/results
	rosbag play output.bag
```
Then the terminal running listener will show messages from chatter topic.

## View tf:
run tf broadcaster:
```
	roscore
```

in new terminal: there will be two frames, one is world and one is talk, talk frame has position: x=1 and orientaion: yaw=1.57 with regarding to the world frame as origin frame.
```
	rosrun beginner_tutorials talker
```

View relation between talker and world:
```
	rosrun tf tf_echo /world /talk
	rosrun rqt_tf_tree rqt_tf_tree
```

to view the frames: there will be frames.pdf which shows all information of frames
```
	roscd beginner_tutorials/results && rosrun tf view_frames
```

## Run rostest:
rostest in this project tests transformation of frames between talk and world frame. The test file also test if talker file publish correct message.

build the test, assume already run catkin_make, in catkin work space:
```
	catkin_make run_tests
```

run test launch file:
```
	rostest beginner_tutorials test.launch
```

## Notes and Known Issues
Since the officially recommended way to write callback function of server is using "Server_Type::Request  &req" instead of pointer, so cpplint would show issue of using pointer.

