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
	roslaunch beginner_tutorials services.launch [default:=default rate:=1]
```
Where user can change value of rate. In extra terminals, there will be talker and listeners information. default value is 2, and the range of rate is from 1 to 20, if user set value out of the range, code will use nearest values available in the range. 
---
Run server and client:
open terminal:
```
	roslaunch beginner_tutorials services.launch [default:=default value1:=0 value2:=1]
```
Where user can change values of value1 and value2. In extra terminal, there will be sum of the two values. Dedault value of value1 and value2 are 1 and 2.
Terminal also shows testing messages of all 5 loggings.

## Notes and Known Issues
Since the officially recommended way to write callback function of server is using "Server_Type::Request  &req" instead of pointer, so cpplint would show issue of using pointer.