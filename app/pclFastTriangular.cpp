/*
 * pclFastTriangular.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: viki
 */

#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <ios>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pclFastTriangular.h>
#include <vector>
using namespace pcl;

pclFastTriangular::pclFastTriangular() {
  searchRadius = 0;
}

void pclFastTriangular::setSearchRadius(double radius) {
  searchRadius = radius;
}
double pclFastTriangular::getSearchRadius()
{
  return searchRadius;
}
void pclFastTriangular::setInputCloud(PointCloud<PointNormal>& cloudIn)
{
  cloud = cloudIn;
}
void pclFastTriangular::getInputCloud(PointCloud<PointNormal>& cloudOut)
{
  cloudOut = cloud;
}
void pclFastTriangular::reconctruct(pcl::PolygonMesh& triangles)
{
  pcl::search::KdTree<pcl::PointNormal>::Ptr tree(
      new pcl::search::KdTree<pcl::PointNormal>);
  cloudPtr = cloud.makeShared();
  tree->setInputCloud(cloudPtr);

  // Set the maximum distance between connected points (maximum edge length)
  gp3.setSearchRadius(searchRadius);

  // Set typical values for the parameters
  gp3.setMu(2.5);
  gp3.setMaximumNearestNeighbors(100);
  gp3.setMaximumSurfaceAngle(M_PI / 4);  // 45 degrees
  gp3.setMinimumAngle(M_PI / 18);  // 10 degrees
  gp3.setMaximumAngle(2 * M_PI / 3);  // 120 degrees
  gp3.setNormalConsistency(false);

  // Get result
  gp3.setInputCloud(cloudPtr);
  gp3.setSearchMethod(tree);
  gp3.reconstruct(triangles);

}

std::vector<int> pclFastTriangular::getSegID() {
  return gp3.getPartIDs();
}








