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

  void dispaly(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud);

 private:
  int user_data;
};



#endif /* INCLUDE_PCLCLOUDVIEWER_H_ */
