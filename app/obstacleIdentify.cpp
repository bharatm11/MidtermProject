/*
 * obstacleIdentify.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: Michael
 */
#include <obstacleIdentify.h>



  obstacleIdentify::obstacleIdentify() {
  normalZ = 0;
  zHeight = 0;
}
void obstacleIdentify::setNormalZ(double zNormal) {
  normalZ = zNormal;

}
double obstacleIdentify::getNormalZ() {
  return normalZ;
}
void obstacleIdentify::setZHeight(double height) {
  zHeight = height;
}
double obstacleIdentify::getZHeight() {
  return zHeight;
}
void obstacleIdentify::setInputCloud(PointCloud<PointNormal>& cloudIn) {
  cloud = cloudIn;
}
void obstacleIdentify::getInputCloud(PointCloud<PointNormal>& cloudOut) {
  cloudOut = cloud;
}
void obstacleIdentify::process(PointCloud<PointNormal>& cloudOut) {


  for (size_t i = 0; i < cloud.points.size(); ++i) {
    // obstacle
    if (cloud.points[i].normal_z < normalZ) {  // mark as obstacle
      cloudOut.push_back(cloud.points[i]);
    }
  }
}




