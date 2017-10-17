/*
 * obstacleIdentifyTest.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: viki
 */
#include <gtest/gtest.h>
#include <obstacleIdentify.h>

TEST(obstacleIdentifyTest, setZHeight) {
  obstacleIdentify oi;
  oi.setZHeight(1);
  double zHeight = oi.getZHeight();
  EXPECT_NEAR(1, zHeight, 0.1);
}

TEST(obstacleIdentifyTest, setZNormal) {
  obstacleIdentify oi;
  oi.setNormalZ(1.3);
  double zNormal = oi.getNormalZ();
  EXPECT_NEAR(1.3, zNormal, 0.1);
}
TEST(obstacleIdentifyTest, setpclCloud) {
  obstacleIdentify oi;
  pcl::PointCloud<pcl::PointNormal>::Ptr cloud(
      new pcl::PointCloud<pcl::PointNormal>);
  pcl::PointCloud<pcl::PointNormal>::Ptr cloudGet(
      new pcl::PointCloud<pcl::PointNormal>);
  cloud->width = 2;
  cloud->height = 1;
  cloud->points.resize(cloud->width * cloud->height);
  //define point cloud
  cloud->points[0].x = 3;
  cloud->points[0].y = 0.2;
  cloud->points[0].z = -1.2;
  cloud->points[1].x = 1.2;
  cloud->points[1].y = 2.3;
  cloud->points[1].z = 1.4;
  oi.setInputCloud(*cloud);
  oi.getInputCloud(*cloudGet);
  int originSize = cloud->width * cloud->height;
  int getInputSize = cloudGet->width * cloudGet->height;
  EXPECT_EQ(originSize, getInputSize);
  EXPECT_NEAR(-1.2, cloudGet->points[0].z, 0.1);
}

TEST(obstacleIdentifyTest, process) {
  obstacleIdentify oi;
  pcl::PointCloud<pcl::PointNormal>::Ptr cloud(
      new pcl::PointCloud<pcl::PointNormal>);
  pcl::PointCloud<pcl::PointNormal>::Ptr cloudOut(
      new pcl::PointCloud<pcl::PointNormal>);
  cloud->width = 2;
  cloud->height = 1;
  cloud->points.resize(cloud->width * cloud->height);
  //define point cloud
  cloud->points[0].x = 3;
  cloud->points[0].y = 0.2;
  cloud->points[0].z = -1.2;
  cloud->points[0].normal_z = 1;
  cloud->points[1].x = 1.2;
  cloud->points[1].y = 2.3;
  cloud->points[1].z = 1.4;
  cloud->points[1].normal_z = 0.7;
  oi.setInputCloud(*cloud);
  oi.setNormalZ(0.8);
  oi.process(*cloudOut);
  double normalZ = cloudOut->points[0].normal_z;
  EXPECT_NEAR(0.7, normalZ, 0.05);


}
