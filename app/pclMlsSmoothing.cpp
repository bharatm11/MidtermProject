/*
 * pclMlsSmoothing.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: viki
 */
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <ios>
#include <pclMlsSmoothing.h>
using namespace pcl;

pclMlsSmoothing::pclMlsSmoothing() {
  searchRadius = 0;
}

void pclMlsSmoothing::setSearchRadius(double radius) {
  searchRadius = radius;

}
double pclMlsSmoothing::getSearchRadius() {
  return searchRadius;
}
void pclMlsSmoothing::setInputCloud(PointCloud<PointXYZ>& cloudIn) {
  cloud = cloudIn;
}
void pclMlsSmoothing::getInputCloud(PointCloud<PointXYZ>& cloudOut)
{
  cloudOut = cloud;
}
void pclMlsSmoothing::mlsProcess(PointCloud<PointNormal>& mls_points)
{
  pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(
      new pcl::search::KdTree<pcl::PointXYZ>);
  //pcl::PointCloud<pcl::PointNormal> mls_points;

  pcl::MovingLeastSquares<pcl::PointXYZ, pcl::PointNormal> mls;
  mls.setComputeNormals(true);
  cloudPtr = cloud.makeShared();
  // Set parameters
  mls.setInputCloud(cloudPtr);
  mls.setPolynomialFit(true);
  mls.setSearchMethod(tree);
  mls.setSearchRadius(searchRadius);

  // Reconstruct
  mls.process(mls_points);

}
