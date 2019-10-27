# beginner_tutorials
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
---
## Overview
beginner_tutorials is a project followed ROS tutorials, the project contains communicating string message by publisher and subscriber functions and also add operation by server and client function.

## assumptions
system is Ubuntu 16.04;

## dependencies
ROS Kinetic
c++ 11

## Build Instructions
```
cd ~
mkdir catkin_ws
cd catkin_ws
mkdir src
cd src
git clone https://github.com/jingCGM/beginner_tutorials.git
cd ..
catkin_make
echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
```

## Run executable files:


Run publisher and subscriber:
open 1st terminal:
```
	roscore
```
open 2nd terminal:
```
	rosrun beginner_tutorials talker 
```
open 3rd terminal:
```
	rosrun beginner_tutorials listener
```
---
Run server and client:
open 1st terminal:
```
	roscore
```
open 2nd terminal:
```
	rosrun beginner_tutorials add_two_ints_server 
```
open 3rd terminal:
```
	rosrun beginner_tutorials add_two_ints_client 1 2
```


## Notes and Known Issues
Since the officially recommended way to write callback function of server is using "Server_Type::Request  &req" instead of pointer, so cpplint would show issue of using pointer.