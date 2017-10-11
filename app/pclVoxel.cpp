/*
 * pclVoxel.cpp
 *
 *  Created on: Oct 10, 2017
 *      Author: viki
 */
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <vector>
#include <ios>
#include "pclVoxel.h"
using std::vector;
using namespace pcl;


void pclVoxel::filterProcess(PointCloud<PointXYZ>& cloud_out) {

  pcl::VoxelGrid<pcl::PointXYZ> sor;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloudPtr(
      new pcl::PointCloud<pcl::PointXYZ>);
  sor.setInputCloud(cloudPtr);
  sor.setLeafSize(lx, ly, lz);
  sor.filter(cloud_out);

}

void pclVoxel::getInputCloud(PointCloud<PointXYZ>& cloud_out) {
  cloud_out = cloud;
}

vector<float> pclVoxel::getLeafSize() {
  vector<float> leafvalue(3);
  leafvalue[0] = lx;
  leafvalue[0] = ly;
  leafvalue[0] = lz;
  return leafvalue;
}

pclVoxel::pclVoxel() {
  lx = 0;
  ly = 0;
  lz = 0;
}

void pclVoxel::setInputCloud(PointCloud<PointXYZ>& cloud_in) {
  cloud = cloud_in;
}

void pclVoxel::setLeafSize(float setLx, float setLy, float setLz) {
  lx = setLx;
  ly = setLy;
  lz = setLz;
}
