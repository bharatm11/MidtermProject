/*
 * pclCloudViewer.cpp
 *
 *  Created on: Oct 6, 2017
 *      Author: viki
 */
#include <pcl/visualization/cloud_viewer.h>
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "pclCloudViewer.h"


#ifndef TEST
#define FOREVER()1
#else
#define FOREVER()0
#endif


pclCloudViewer::pclCloudViewer()
{
  user_data = 0;
}

void pclCloudViewer::dispaly(
    const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud) {

  pcl::visualization::CloudViewer viewer("Cloud Viewer");

  viewer.showCloud(cloud);

  do {
    user_data++;
  } while (!viewer.wasStopped() && FOREVER());

}

