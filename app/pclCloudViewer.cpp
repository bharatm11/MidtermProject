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


void pclCloudViewer::dispaly(pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud) {

  user_data = 0;

  pcl::visualization::CloudViewer viewer("Cloud Viewer");

  viewer.showCloud(cloud);

  //viewer.runOnVisualizationThreadOnce(viewerOneOff);

  //viewer.runOnVisualizationThread(viewerPsycho);

  do {
    user_data++;
  } while (!viewer.wasStopped() && FOREVER());

}

void pclCloudViewer::viewerPsycho(pcl::visualization::PCLVisualizer& viewer) {
  static unsigned count = 0;
  std::stringstream ss;
  ss << "Once per viewer loop: " << count++;
  viewer.removeShape("text", 0);
  viewer.addText(ss.str(), 200, 300, "text", 0);

  user_data++;
}

void pclCloudViewer::viewerOneOff(pcl::visualization::PCLVisualizer& viewer) {
  viewer.setBackgroundColor(1.0, 0.5, 1.0);
  pcl::PointXYZ o;
  o.x = 1.0;
  o.y = 0;
  o.z = 0;
  viewer.addSphere(o, 0.25, "sphere", 0);
  std::cout << "i only run once" << std::endl;

}


