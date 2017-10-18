// "Copyright [2017] <Michael Kam>"
/** @file pclFastTriangular.cpp
 *  @brief This is the implementation of the pclFastTriangular class. This class consists of 6 methods.
 *  Please refer the pclFastTriangular.h for more detail.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 *  @copyright GNU Public License.
 */

#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pclFastTriangular.h>
#include <ios>
#include <vector>
#include <iostream>
// using namespace pcl;

pclFastTriangular::pclFastTriangular() {
  searchRadius = 0;
}

void pclFastTriangular::setSearchRadius(double radius) {
  searchRadius = radius;
}
double pclFastTriangular::getSearchRadius() {
  return searchRadius;
}
void pclFastTriangular::setInputCloud(
    pcl::PointCloud<pcl::PointNormal>& cloudIn) {
  cloud = cloudIn;
}
void pclFastTriangular::getInputCloud(
    pcl::PointCloud<pcl::PointNormal>& cloudOut) {
  cloudOut = cloud;
}
void pclFastTriangular::reconctruct(pcl::PolygonMesh& triangles) {
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

