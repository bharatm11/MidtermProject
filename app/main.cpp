// "Copyright [2017] <Michael Kam>"
/** @file main.cpp
 *  @brief main.cpp is a main file of shell-app.
 **
 *  This main file demonstrate using point cloud library to detect obstacles.
 *  This demo follow the procedures in the activity diagram under the UML directory.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 *  @copyright GNU Public License.
 */
#include "pclIo.h"
#include "pclVoxel.h"
#include "pclMlsSmoothing.h"
#include "pclPassThrough.h"
#include "pclStatisticalOutlierRemoval.h"
#include "pclFastTriangular.h"
#include "pclCloudViewer.h"
#include "obstacleIdentify.h"
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/visualization/cloud_viewer.h>
#include <iostream>

#include <boost/make_shared.hpp>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/point_representation.h>

#include <pcl/io/pcd_io.h>

#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/filter.h>

#include <pcl/features/normal_3d.h>

#include <pcl/registration/icp.h>
#include <pcl/registration/icp_nl.h>
#include <pcl/registration/transforms.h>

#include <pcl/visualization/pcl_visualizer.h>
#include <cstdio>
#include <ctime>

using pcl::visualization::PointCloudColorHandlerGenericField;
using pcl::visualization::PointCloudColorHandlerCustom;

//convenient typedefs
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloud;
typedef pcl::PointNormal PointNormalT;
typedef pcl::PointCloud<PointNormalT> PointCloudWithNormals;
pclStatistOutRev sor;
pclMlsSmoothing mls;
pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normal(
		new pcl::PointCloud<pcl::PointNormal>);
// This is a tutorial so we can afford having global variables
//our visualizer
pcl::visualization::PCLVisualizer *p;
//its left and right viewports
int vp_1, vp_2;

// using namespace pcl::io;

int main() {
	std::clock_t start;
	double duration;
	start = std::clock();

	// 0. Initialization
	pclIo pclLoad;
	pclCloudViewer pclView;
	pclPassThrough pt;
	pclVoxel vx;
	pclStatistOutRev sor;
	obstacleIdentify oi;
	pclMlsSmoothing mls;
	pclFastTriangular ft;
	pcl::PolygonMesh triangles;
	pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normal(
			new pcl::PointCloud<pcl::PointNormal>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out(
			new pcl::PointCloud<pcl::PointXYZ>);
	//  1. Load pcd file
	std::cout << " 1. Loading pcd file, please wait..." << std::endl;
	pclLoad.readPCDfile("../PCL_Matlab_Result__ROI_Modified_ascii.pcd");
	pclLoad.getPointCloud(*cloud_out);
	/*
	pcl::visualization::CloudViewer viewer("Cloud of Raw data");
	viewer.showCloud(cloud_out);
	int user_data = 0;
	do {
		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

		std::cout << "printf: " << duration << '\n';
		user_data++;
	} while (!viewer.wasStopped());
	*/
	std::cout << " Loading completed" << std::endl;
	//  2. Remove the noise of point cloud
	std::cout << " 2. Removing the noise of point cloud, please wait..."
			<< std::endl;
	sor.setInputCloud(*cloud_out);
	sor.setMeanK(50);
	sor.setStddevMulThresh(1);
	sor.filterProcess(*cloud_out);
	std::cout << " Removing completed" << std::endl;
	//  3. Extract certain region of point cloud
	/*std::cout << " 3. Extracting certain region of point cloud, please wait..."
	 << std::endl;
	 pt.setFilterZlimit(0.0, 8.0);
	 pt.setInputCloud(*cloud_out);
	 pt.filterProcess(*cloud_out);
	 std::cout << " Extracting completed" << std::endl;
	 //  4. Down sample the point cloud
	 std::cout << " 4. Down sampling the point cloud, please wait..." << std::endl;
	 vx.setInputCloud(*cloud_out);
	 vx.setLeafSize(0.001, 0.001, 0.001);
	 vx.filterProcess(*cloud_out);
	 std::cout << " Down sampling completed" << std::endl;*/
	//  5. Smooth the point cloud
	std::cout << " 5. Smoothing the point cloud, please wait..." << std::endl;
	mls.setInputCloud(*cloud_out);
	mls.setSearchRadius(4);
	mls.mlsProcess(*cloud_with_normal);
	std::cout << " Smoothing completed" << std::endl;

	pcl::io::savePCDFile("pointCloudFile.pcd", *cloud_with_normal);
	//  6. Identify obstacle
	/*
	 std::cout << " 6. Identifying obstacle, please wait..." << std::endl;
	 oi.setInputCloud(*cloud_with_normal);
	 oi.setNormalZ(0.8);
	 oi.process(*cloud_with_normal);
	 std::cout << " Identifying completed, please wait..." << std::endl;
	 //  7. Mesh the obstacle
	 std::cout << " 7. Meshing the obstacle, please wait..." << std::endl;
	 ft.setInputCloud(*cloud_with_normal);
	 ft.setSearchRadius(0.05);
	 ft.reconctruct(triangles);
	 std::cout << " Meshing completed..." << std::endl;
	 //  8. Show the result
	 pclView.display(triangles);
	 */

	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

	std::cout << "printf: " << duration << '\n';

	return 0;
}

