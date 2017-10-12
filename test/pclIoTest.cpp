/*
 * pclIoTest.cpp
 *
 *  Created on: Oct 6, 2017
 *      Author: Michael
 */

#include <iostream>
#include "pclIo.h"
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <gtest/gtest.h>


TEST(pclIoTest, loadPCDfileMustFail) {
  pclIo pclLoad;
  int load = pclLoad.readPCDfile("no_such_file.pcd");
  EXPECT_NEAR(-1, load, 0.5);
}

TEST(pclIoTest, loadPCDfileShowResult) {
  pclIo pclLoad;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  pclLoad.readPCDfile("../pclIo_test.pcd");
  pclLoad.getPointCloud(*cloud);
  EXPECT_NEAR(10, cloud->points[0].x, 0.5);
  EXPECT_NEAR(20, cloud->points[0].y, 0.5);
  EXPECT_NEAR(30, cloud->points[0].z, 0.5);
}

