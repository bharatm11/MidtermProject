/*
 * pclPassThrough.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: viki
 */

#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include <vector>
#include "pclPassThrough.h"
using namespace pcl;
using std::vector;

pclPassThrough::pclPassThrough() {
  zMin = 0;
  zMax = 0;
  yMin = 0;
  yMax = 0;
  xMin = 0;
  xMax = 0;

}
void pclPassThrough::setInputCloud(PointCloud<PointXYZ>& cloud_in) {
  cloud = cloud_in;
}
void pclPassThrough::getInputCloud(PointCloud<PointXYZ>& cloud_out)
{
  cloud_out = cloud;
}


void pclPassThrough::setFilterXlimit(const float& setXMax,
                                     const float& setXMin)
{
  xMax = setXMax;
  xMin = setXMin;
  pass.setFilterFieldName("x");
  pass.setFilterLimits(xMin, xMax);

}
void pclPassThrough::setFilterYlimit(const float& setYMax,
                                     const float& setYMin)
{
  yMax = setYMax;
  yMin = setYMin;
  pass.setFilterFieldName("y");
  pass.setFilterLimits(yMin, yMax);

}
void pclPassThrough::setFilterZlimit(const float& setZMax,
                                     const float& setZMin)
{
  zMax = setZMax;
  zMin = setZMin;
  pass.setFilterFieldName("z");
  pass.setFilterLimits(zMin, zMax);

}
void pclPassThrough::filterProcess(PointCloud<PointXYZ>& cloud_out)
{
  cloudPtr = cloud.makeShared();
  pass.setInputCloud(cloudPtr);
  pass.filter(cloud_out);

}

vector<float> pclPassThrough::getFilterLimit() {
  vector<float> limitValue(6);
  limitValue[0] = xMin;
  limitValue[1] = xMax;
  limitValue[2] = yMin;
  limitValue[3] = yMax;
  limitValue[4] = zMin;
  limitValue[5] = zMax;
  return limitValue;
}

