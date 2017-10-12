#include <iostream>
#include <lib.hpp>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
using namespace pcl::io;
#include <pcl/filters/statistical_outlier_removal.h>
#include "pclCloudViewer.h"
#include <pcl/visualization/cloud_viewer.h>
#include "pclIo.h"
#include "pclVoxel.h"


int main()
{

  pclIo pclLoad;
  pclCloudViewer pclView;
  pclVoxel pclvoxel;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out(
      new pcl::PointCloud<pcl::PointXYZ>);
  pclLoad.readPCDfile("PCL_Matlab_Result__ROI_Smoothing_ascii.pcd");
  /* pclLoad.getPointCloud(*cloud_out);
   pclView.dispaly(cloud_out);*/
  pclLoad.getPointCloud(*cloud);
  pclvoxel.setLeafSize(0.5, 0.5, 0.5);
  pclvoxel.setInputCloud(*cloud);
  pclvoxel.filterProcess(*cloud_out);
  pclView.dispaly(cloud_out);
  /*  pcl::visualization::CloudViewer viewer("Cloud Viewer");

  //blocks until the cloud is actually rendered
  viewer.showCloud(cloud);

  //use the following functions to get access to the underlying more advanced/powerful
  //PCLVisualizer

  //This will only get called once
  viewer.runOnVisualizationThreadOnce(viewerOneOff);

  //This will get called once per visualization iteration
  viewer.runOnVisualizationThread(viewerPsycho);
  while (!viewer.wasStopped()) {
    //you can also do cool processing here
    //FIXME: Note that this is running in a separate thread from viewerPsycho
    //and you should guard against race conditions yourself...
    user_data++;
   }*/
  return 0;
}
