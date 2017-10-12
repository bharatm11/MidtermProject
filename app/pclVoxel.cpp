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


void pclVoxel::filterProcess(PointCloud<PointXYZ>& cloudOut) {

  pcl::VoxelGrid<pcl::PointXYZ> sor;
  cloudPtr = cloud.makeShared();  //!!!!! Nice work!!!
  sor.setInputCloud(cloudPtr);
  sor.setLeafSize(lx, ly, lz);
  sor.filter(cloudOut);

}

void pclVoxel::getInputCloud(PointCloud<PointXYZ>& cloudOut) {
  cloudOut = cloud;
}

vector<float> pclVoxel::getLeafSize() {
  vector<float> leafvalue(3);
  leafvalue[0] = lx;
  leafvalue[1] = ly;
  leafvalue[2] = lz;
  return leafvalue;
}

pclVoxel::pclVoxel() {
  lx = 0;
  ly = 0;
  lz = 0;
}

void pclVoxel::setInputCloud(PointCloud<PointXYZ>& cloudIn) {
  cloud = cloudIn;
}

void pclVoxel::setLeafSize(float setLx, float setLy, float setLz) {
  lx = setLx;
  ly = setLy;
  lz = setLz;
}
