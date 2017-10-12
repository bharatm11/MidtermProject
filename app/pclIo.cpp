/*
 * pclIo.cpp
 *
 *  Created on: Oct 6, 2017
 *      Author: viki
 */

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "pclIo.h"
using namespace pcl;

pclIo::pclIo() {

}

int pclIo::readPCDfile(const std::string& fileName) {
  if (pcl::io::loadPCDFile<pcl::PointXYZ>(fileName, cloud) == -1)
      {
    PCL_ERROR("Couldn't read file test_pcd.pcd \n");
    return (-1);
  }
  return 0;
}

void pclIo::getPointCloud(PointCloud<PointXYZ>& cloudOut) {
  cloudOut = cloud;
}
