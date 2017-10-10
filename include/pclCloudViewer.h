/*
 * pclCloudViewer.h
 *
 *  Created on: Oct 6, 2017
 *      Author: Michael
 */

#ifndef INCLUDE_PCLCLOUDVIEWER_H_
#define INCLUDE_PCLCLOUDVIEWER_H_

#include <pcl/visualization/cloud_viewer.h>//           !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>


class pclCloudViewer {
 public:
  pclCloudViewer();

  void dispaly(pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud);
  int user_data;

 private:

  void viewerOneOff(pcl::visualization::PCLVisualizer& viewer);


  void viewerPsycho(pcl::visualization::PCLVisualizer& viewer);

};



#endif /* INCLUDE_PCLCLOUDVIEWER_H_ */
