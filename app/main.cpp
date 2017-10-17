// "Copyright [2017] <Michael Kam>"
/** @file main.cpp
 *  @brief main file of this project
 **
 *  The shell-app start from this file.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 */
#include "pclIo.h"
#include "pclVoxel.h"
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include "pclCloudViewer.h"
#include <pcl/visualization/cloud_viewer.h>
#include <iostream>
// using namespace pcl::io;

int main() {
  pclIo pclLoad;
  pclCloudViewer pclView;
  pclVoxel pclvoxel;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out(
      new pcl::PointCloud<pcl::PointXYZ>);
  // load pcd file using
  pclLoad.readPCDfile("../PCL_Test.pcd");
  pclView.dispaly(cloud);
  return 0;
}
