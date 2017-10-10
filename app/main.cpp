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

//int user_data;
/*
void viewerOneOff(pcl::visualization::PCLVisualizer& viewer) {
  viewer.setBackgroundColor(0.0, 0.0, 0.0);
  pcl::PointXYZ o;
  o.x = 1.0;
  o.y = 0;
  o.z = 0;
  viewer.addSphere(o, 0.25, "sphere", 0);
  std::cout << "i only run once" << std::endl;

}

void viewerPsycho(pcl::visualization::PCLVisualizer& viewer) {
  static unsigned count = 0;
  std::stringstream ss;
  ss << "Once per viewer loop: " << count++;
  viewer.removeShape("text", 0);
  viewer.addText(ss.str(), 200, 300, "text", 0);

  //FIXME: possible race condition here:
  user_data++;
}
 */

int main()
{
  pclIo pclLoad;
  pclCloudViewer pclView;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  int load = pclLoad.readPCDfile("PCL_Matlab_Result__ROI_Smoothing_ascii.pcd");
  pclLoad.getPointCloud(*cloud);
  pclView.dispaly(cloud);
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
