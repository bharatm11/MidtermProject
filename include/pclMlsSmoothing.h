/*
 * pclMlsSmoothing.h
 *
 *  Created on: Oct 15, 2017
 *      Author: viki
 */

#ifndef INCLUDE_PCLMLSSMOOTHING_H_
#define INCLUDE_PCLMLSSMOOTHING_H_
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/mls.h>
#include <vector>
#include <ios>
using namespace pcl;

class pclMlsSmoothing {
 private:
  PointCloud<PointXYZ> cloud;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloudPtr;
  double searchRadius;
 public:
  pclMlsSmoothing();
  void setSearchRadius(double radius);
  double getSearchRadius();
  void setInputCloud(PointCloud<PointXYZ>& cloudIn);
  void getInputCloud(PointCloud<PointXYZ>& cloudOut);
  void mlsProcess(PointCloud<PointNormal>& cloudOut);

};
#endif /* INCLUDE_PCLMLSSMOOTHING_H_ */
