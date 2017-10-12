/*
 * pclVoxel.h
 *
 *  Created on: Oct 10, 2017
 *      Author: viki
 */

#ifndef INCLUDE_PCLVOXEL_H_
#define INCLUDE_PCLVOXEL_H_
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <vector>
#include <ios>
using std::vector;
using namespace pcl;

class pclVoxel {
 private:
  float lx;
  float ly;
  float lz;
  PointCloud<PointXYZ> cloud;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloudPtr;
 public:
  pclVoxel();
  void setLeafSize(float lx, float ly, float lz);

  vector<float> getLeafSize();

  void setInputCloud(PointCloud<PointXYZ>& cloudIn);
  void getInputCloud(PointCloud<PointXYZ>& cloudOut);
  void filterProcess(PointCloud<PointXYZ>& cloudOut);

};


#endif /* INCLUDE_PCLVOXEL_H_ */
