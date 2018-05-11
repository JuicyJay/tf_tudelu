/*
 * tf_listener.cpp
 *
 *  Created on: May 7, 2018
 *      Author: juicy
 */

#include <ros/ros.h>
#include <tf/transform_listener.h>

int main(int argc, char **argv)
{

	ros::init(argc, argv, "tf_listener");

	ros::NodeHandle nh;
	ros::NodeHandle prvNh("~");

	//for launchfile
	std::string tfFrameFrom;
	prvNh.param<std::string>("tf_frame_from", tfFrameFrom, "hanskaschpo");

	std::string tfFrameTo;
	prvNh.param<std::string>("tf_frame_to", tfFrameTo, "hanskaschpodos");

	tf::TransformListener listener;


	ros::Rate rate(10.0);
	while(nh.ok()){
	tf::StampedTransform transformSaved;
	try
	{
		listener.lookupTransform(tfFrameFrom, tfFrameTo ,ros::Time(0), transformSaved);
	}
	catch(tf::TransformException& ex)
	{
		ROS_ERROR("%s",ex.what());
		ros::Duration(1.0).sleep();
		continue;
	}

	rate.sleep();
	}

	return 0;
}



