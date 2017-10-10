/*
 * pclCloudViewerTest.cpp
 *
 *  Created on: Oct 9, 2017
 *      Author: Michael
 */
#include <gtest/gtest.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <iostream>
#include "pclIo.h"
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/surface/mls.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/filters/passthrough.h>
//#include "pclCloudViewer.h"
/*
TEST(pclCloudViewerTest, MustReturnUserdataEqualto1) {
  pclCloudViewer pclView;
  pclIo pclIo;
  pclIo.readPCDfile("pclIo_test.pcd");
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  pclIo.getPointCloud(*cloud);
  pclView.dispaly(cloud);
  EXPECT_NEAR(1, pclView.user_data, 0.5);
}
 */
