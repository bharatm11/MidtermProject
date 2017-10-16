/*
 * pclFastTriangular.h
 *
 *  Created on: Oct 16, 2017
 *      Author: viki
 */

#ifndef INCLUDE_PCLFASTTRIANGULAR_H_
#define INCLUDE_PCLFASTTRIANGULAR_H_
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <vector>
#include <ios>
using namespace pcl;

class pclFastTriangular {

 private:
  PointCloud<PointNormal> cloud;
  pcl::PointCloud<pcl::PointNormal>::Ptr cloudPtr;
  //std::vector<std::vector<size_t> > vertices;
  pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;
  double searchRadius;

 public:
  pclFastTriangular();
  void setSearchRadius(double radius);
  double getSearchRadius();
  void setInputCloud(PointCloud<PointNormal>& cloudIn);
  void getInputCloud(PointCloud<PointNormal>& cloudOut);
  void reconctruct(pcl::PolygonMesh& triangles);
  std::vector<int> getSegID();

};


#endif /* INCLUDE_PCLFASTTRIANGULAR_H_ */
