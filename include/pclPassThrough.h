/*
 * pclPassThrough.h
 *
 *  Created on: Oct 11, 2017
 *      Author: viki
 */

#ifndef INCLUDE_PCLPASSTHROUGH_H_
#define INCLUDE_PCLPASSTHROUGH_H_

#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include <vector>
#include <ios>
using namespace pcl;
using std::vector;

class pclPassThrough {

 private:
  PointCloud<PointXYZ> cloud;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloudPtr;
  pcl::PassThrough<pcl::PointXYZ> pass;
  double zMin;
  double zMax;
  double yMin;
  double yMax;
  double xMin;
  double xMax;
 public:
  pclPassThrough();
  void setInputCloud(PointCloud<PointXYZ>& cloud_in);
  void getInputCloud(PointCloud<PointXYZ>& cloud_out);
  void setFilterXlimit(const float& setXMax, const float& setXMin);
  void setFilterYlimit(const float& setYMax, const float& setYMin);
  void setFilterZlimit(const float& setZMax, const float& setZMin);
  void filterProcess(PointCloud<PointXYZ>& cloud_out);
  vector<float> getFilterLimit();
};

#endif /* INCLUDE_PCLPASSTHROUGH_H_ */
