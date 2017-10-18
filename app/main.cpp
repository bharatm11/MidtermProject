// "Copyright [2017] <Michael Kam>"
/** @file main.cpp
 *  @brief main.cpp is a main file of shell-app.
 **
 *  This main file demonstrate using point cloud library to detect obstacles.
 *  This demo follow the procedures in the activity diagram under the UML directory.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 */
#include "pclIo.h"
#include "pclVoxel.h"
#include "pclMlsSmoothing.h"
#include "pclPassThrough.h"
#include "pclStatisticalOutlierRemoval.h"
#include "pclFastTriangular.h"
#include "pclCloudViewer.h"
#include "obstacleIdentify.h"
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/visualization/cloud_viewer.h>
#include <iostream>
// using namespace pcl::io;

int main() {
  // 0. Initialization
  pclIo pclLoad;
  pclCloudViewer pclView;
  pclPassThrough pt;
  pclVoxel vx;
  pclStatistOutRev sor;
  obstacleIdentify oi;
  pclMlsSmoothing mls;
  pclFastTriangular ft;
  pcl::PolygonMesh triangles;
  pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normal(
      new pcl::PointCloud<pcl::PointNormal>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out(
      new pcl::PointCloud<pcl::PointXYZ>);
  //  1. Load pcd file
  pclLoad.readPCDfile("../PCL_Test_Mat.pcd");
  pclLoad.getPointCloud(*cloud_out);
  //  2. Remove the noise of point cloud
  sor.setInputCloud(*cloud_out);
  sor.setMeanK(30);
  sor.setStddevMulThresh(1);
  sor.filterProcess(*cloud_out);
  //  3. Extract certain region of point cloud
  pt.setFilterZlimit(0.0, 8.0);
  pt.setInputCloud(*cloud_out);
  pt.filterProcess(*cloud_out);
  //  4. Down sample the point cloud
  vx.setInputCloud(*cloud_out);
  vx.setLeafSize(0.001, 0.001, 0.001);
  vx.filterProcess(*cloud_out);
  std::cout << " Smoothing a point cloud, please wait..." << std::endl;
  //  5. Smooth the point cloud
  mls.setInputCloud(*cloud_out);
  mls.setSearchRadius(0.05);
  mls.mlsProcess(*cloud_with_normal);
  std::cout << " Smoothing completed" << std::endl;
  //  6. Identify obstacle
  oi.setInputCloud(*cloud_with_normal);
  oi.setNormalZ(0.8);
  oi.process(*cloud_with_normal);
  //  7. Mesh the obstacle
  std::cout << " Reconstructing a surface, please wait..." << std::endl;
  ft.setInputCloud(*cloud_with_normal);
  ft.setSearchRadius(0.05);
  ft.reconctruct(triangles);
  std::cout << " Surface reconstruction completed..." << std::endl;
  //  8. Show the result
  pclView.display(triangles);
  /*
   pcl::visualization::CloudViewer viewer("Cloud Viewer");
   viewer.showCloud(cloud_out);
   int user_data=0;
   do {
   user_data++;
   } while (!viewer.wasStopped());
   */

  return 0;
}
