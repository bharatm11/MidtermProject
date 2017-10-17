// "Copyright [2017] <Michael Kam>"
/** @file pclCloudViewer.cpp
 *  @brief This is the implementation of the pclCloudViewer class. This class consists of 1 method.
 *  Please refer the pclCloudViewer.h for more detail.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 */
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "pclCloudViewer.h"
#include <iostream>

pclCloudViewer::pclCloudViewer() {
  user_data = 0;
}

void pclCloudViewer::dispaly(
    const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud) {
  pcl::visualization::CloudViewer viewer("Cloud Viewer");
  viewer.showCloud(cloud);
  do {
    user_data++;
  } while (!viewer.wasStopped());
}

