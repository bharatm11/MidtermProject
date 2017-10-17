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
  // 1. Load pcd file
  pclLoad.readPCDfile("../PCL_Test_Mat.pcd");
  pclLoad.getPointCloud(*cloud_out);
  // 2. Remove the noise of point cloud
  sor.setInputCloud(*cloud_out);
  sor.setMeanK(30);
  sor.setStddevMulThresh(1);
  sor.filterProcess(*cloud_out);
  // 3. Extract certain region of point cloud
  pt.setFilterZlimit(0.0, 8.0);
  pt.setInputCloud(*cloud_out);
  pt.filterProcess(*cloud_out);
  // 4. Down sample the point cloud
  vx.setInputCloud(*cloud_out);
  vx.setLeafSize(0.001, 0.001, 0.001);
  vx.filterProcess(*cloud_out);
  // 5. Smooth the point cloud
  mls.setInputCloud(*cloud_out);
  mls.setSearchRadius(0.05);
  mls.mlsProcess(*cloud_with_normal);
  // 6. Identify obstacle
  oi.setInputCloud(*cloud_with_normal);
  oi.setNormalZ(0.8);
  oi.process(*cloud_with_normal);
  // 7. Mesh the obstacle
  ft.setInputCloud(*cloud_with_normal);
  ft.setSearchRadius(0.05);
  ft.reconctruct(triangles);
  // 8. Show the result
  boost::shared_ptr<pcl::visualization::PCLVisualizer> gp3viewer(
      new pcl::visualization::PCLVisualizer("3D Viewer"));
  gp3viewer->setBackgroundColor(0, 0, 0);
  gp3viewer->addPolygonMesh(triangles, "meshes", 0);
  gp3viewer->addCoordinateSystem(1.0);
  while (!gp3viewer->wasStopped()) {
    gp3viewer->spinOnce(100);
  }

  return 0;
}
