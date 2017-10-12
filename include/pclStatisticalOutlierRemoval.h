/*
 * pclStatisticalOutlierRemoval.h
 *
 *  Created on: Oct 12, 2017
 *      Author: viki
 */

#ifndef INCLUDE_PCLSTATISTICALOUTLIERREMOVAL_H_
#define INCLUDE_PCLSTATISTICALOUTLIERREMOVAL_H_
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <vector>
#include <ios>
using namespace pcl;
using std::vector;

class pclStatistOutRev {
 private:
  pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
  PointCloud<PointXYZ> cloud;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloudPtr;
  int ktree;
  double standDevMulThresh;
 public:
  pclStatistOutRev();
  void setInputCloud(PointCloud<PointXYZ>& cloudIn);
  void getInputCloud(PointCloud<PointXYZ>& cloudOut);
  void filterProcess(PointCloud<PointXYZ>& cloudOut);
  int getMeanK();
  void setMeanK(int setktree);
  double getStddevMulThresh();
  void setStddevMulThresh(double Thresh);

};




#endif /* INCLUDE_PCLSTATISTICALOUTLIERREMOVAL_H_ */
