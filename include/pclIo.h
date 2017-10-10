/*
 * pclIo.h
 *
 *  Created on: Oct 7, 2017
 *      Author: viki
 */

#ifndef INCLUDE_PCLIO_H_
#define INCLUDE_PCLIO_H_

 #include <iostream>
#include <pcl/io/io.h>
 #include <pcl/io/pcd_io.h>
 #include <pcl/point_types.h>

using namespace pcl;

class pclIo {
 public:

  pclIo();

  int readPCDfile(const std::string& file_name);

  void getPointCloud(PointCloud<PointXYZ>& cloud_out);

 private:
  PointCloud<PointXYZ> cloud;

};



#endif /* INCLUDE_PCLIO_H_ */
