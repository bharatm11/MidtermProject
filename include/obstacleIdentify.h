/*
 * obstacleIdentify.h
 *
 *  Created on: Oct 16, 2017
 *      Author: viki
 */

#ifndef INCLUDE_OBSTACLEIDENTIFY_H_
#define INCLUDE_OBSTACLEIDENTIFY_H_
#include <iostream>
#include <vector>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
using namespace pcl;

class obstacleIdentify
{
private:
  PointCloud<PointNormal> cloud;
  pcl::PointCloud<pcl::PointNormal>::Ptr cloudPtr;
  double zHeight;
  double normalZ;

public:
  obstacleIdentify();
  void setNormalZ(double zNormal);
  double getNormalZ();
  void setZHeight(double height);
  double getZHeight();
  void setInputCloud(PointCloud<PointNormal>& cloudIn);
  void getInputCloud(PointCloud<PointNormal>& cloudOut);
  void process(PointCloud<PointNormal>& cloudOut);

};



#endif /* INCLUDE_OBSTACLEIDENTIFY_H_ */
