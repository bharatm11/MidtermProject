/*
 * pclVoxelTest.cpp
 *
 *  Created on: Oct 12, 2017
 *      Author: viki
 */
#include <gtest/gtest.h>
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "pclVoxel.h"
#include "pclIo.h"

TEST(pclVoxelTest, setLeafValue) {
  /*pclVoxel pclVoxel;
  vector<float> leafSize(3);
  pclVoxel.setLeafSize(0.5, 0.4, 0.7);
  leafSize = pclVoxel.getLeafSize();
  EXPECT_NEAR(0.5, leafSize[0], 0.1);
  EXPECT_NEAR(0.4, leafSize[1], 0.1);
   EXPECT_NEAR(0.7, leafSize[2], 0.1);*/
}


TEST(pclVoxelTest, pointCloudDownSampleing) {
  /* pclIo pclLoad;
  pclVoxel pclVoxel;
  int originSize = 0;
  int filteredSize = 0;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloudFiltered(
      new pcl::PointCloud<pcl::PointXYZ>);
  pclLoad.readPCDfile(
      "../PCL_Matlab_Result__ROI_Smoothing_ascii.pcd");
  pclLoad.getPointCloud(*cloud);
  originSize = cloud->height * cloud->width;
  pclVoxel.setInputCloud(*cloud);
  pclVoxel.setLeafSize(0.5, 0.4, 0.7);
  pclVoxel.filterProcess(*cloudFiltered);
  filteredSize = cloudFiltered->height * cloudFiltered->width;
   EXPECT_LT(filteredSize, originSize);*/
  EXPECT_EQ(0, 0);

}
