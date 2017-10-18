# C++ Boilerplate
[![Build Status](https://travis-ci.org/michael081906/MidtermProject.svg?branch=master)](https://travis-ci.org/michael081906/MidtermProject)
[![Coverage Status](https://coveralls.io/repos/github/michael081906/MidtermProject/badge.svg?branch=master)](https://coveralls.io/github/michael081906/MidtermProject?branch=master)
---

## Overview and purpose of the project 

This project goal is to develop a module that utilizes PCL library to detect an obstacle in front of a robot. This project created eight classes and utilizes them to complete the task. First, a class, pclIo, loads point cloud data from file. Second, a class, pclStatisticalOutlierRemoval, removes noise in point cloud. Third, a class, pclPassThrough, extracts certain range of point cloud data based on setting coordinate threshold. Fourth, a class, pclVoxel, down samples point cloud data, making less data to compute. Fifth, a class, pclMlsSmoothing, smooths point cloud so that a class such as obstacleIdentify can identify an obstacle more correctly. Sixth, a class, obstacleIdentify, extracts a normal vector from a point cloud and identifies whether it is an obstacle. Seventh, a class, pclFastTriangular, reconstructs the obstacle’s surface. Lastly, a class, pclCloudViewer, displays the results.

The unit test cases were also created during the implementation stage. There were eight test cases which test eight different classes. For example, pclIoTest is a unit test that tests the pclIo class. The unit test uses function in which target test class has to verify the result. There were in total twenty test cases created for the project and all of them were passed in Travis-CI, and the code coverage of the test was 99.4%. The unit test result can be viewed from Travis-CI, and the code coverage of the testing can be viewed on Coverall (click two badges above to link.)

The result of this project could be view by running the shell-app binary file (please see the build stage below). The total time running the results based on the point cloud data size. The more point cloud data, the more computational time it took. In our case, the time was around 1~2 minute. The results showed that by using this algorithm, an obstacle in the point cloud could be extracted.
 
## TODO
1. Return the distance of the obstacle.
   Due to limited time, a function of returning a distance was not yet finished.


## SIP process link:

https://docs.google.com/spreadsheets/d/1hbsekl-bL_gAPJG16gUsE_9I0f2z8C1L1cXL2aqPpPI/edit#gid=919119936

## License 

Point Cloud Library(pcl) License: Copyright (c) 2012-, Open Perception, Inc.
Doxygen license: Copyright © 1997-2016 by Dimitri van Heesch.
Googletest license: Copyright 2008, Google Inc.


## Dependencies (and how to install if not included in repository)

This project utilizes point cloud library(pcl) to process. Make sure the environment is installed with pcl; Or, you can install point cloud library by typing
```
sudo add-apt-repository ppa:v-launchpad-jochen-sprickerhof-de/pcl
sudo apt-get update
sudo apt-get install libpcl-all
```
Reference: http://pointclouds.org/downloads/linux.html

## Build
```
git clone --recursive https://github.com/michael081906/MidtermProject.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
```
## Run demo

After the Build step, type:
```
./app/shell-app
```
## Run tests

After the Build step, type:
```
./test/cpp-test
```
## doxygen documentation
```
sudo apt install doxygen
cd <path to repository>
mkdir docs
cd docs
doxygen -g Midterm
```
open the Midterm file(which is a configuration file of doxygen), and modify input tag into

INPUT                  = ../include ../src ../test

and then save the file. Back to terminal and type:
```
doxygen Midterm
```
find an index.html in ./html directory, which can be viewed on web browser.



