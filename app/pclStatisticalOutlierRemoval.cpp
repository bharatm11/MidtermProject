/*
 * pclStatisticalOutlierRemoval.cpp
 *
 *  Created on: Oct 12, 2017
 *      Author: viki
 */
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <ios>
#include "pclStatisticalOutlierRemoval.h"
using namespace pcl;
using std::vector;

pclStatistOutRev::pclStatistOutRev() {
  standDevMulThresh = 0;
  ktree = 0;

}
void pclStatistOutRev::setInputCloud(PointCloud<PointXYZ>& cloudIn) {
  cloud = cloudIn;
}
void pclStatistOutRev::getInputCloud(PointCloud<PointXYZ>& cloudOut) {
  cloudOut = cloud;
}
void pclStatistOutRev::filterProcess(PointCloud<PointXYZ>& cloudOut) {
  cloudPtr = cloud.makeShared();
  sor.setInputCloud(cloudPtr);
  sor.setMeanK(ktree);
  sor.setStddevMulThresh(standDevMulThresh);
  sor.filter(cloudOut);
}
int pclStatistOutRev::getMeanK() {
  return ktree;
}
void pclStatistOutRev::setMeanK(int setktree) {
  ktree = setktree;
}
double pclStatistOutRev::getStddevMulThresh() {
  return standDevMulThresh;
}
void pclStatistOutRev::setStddevMulThresh(double thresh) {
  standDevMulThresh = thresh;
}



