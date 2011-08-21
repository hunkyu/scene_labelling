/* 
 * File:   moveRobot.h
 * Author: aa755
 *
 * Created on August 21, 2011, 3:45 PM
 */

#ifndef MOVEROBOT_H
#define	MOVEROBOT_H
#include <ros/ros.h>
#include <iostream>
#include <geometry_msgs/Twist.h>
#include <math.h>

/**
 * not thread safe
 */
class MoveRobot
{
  ros::Publisher cmd_vel_pub_;
    geometry_msgs::Twist base_cmd;
    
    double linearConversion;
    double angularconversion;
    
    double linearSpeedMetresPerSec;
    double angularSpeedDegreePerSeg;
    ros::NodeHandle nh_;
//    double speedDevice;
    
    MoveRobot(ros::NodeHandle &nh)
    {
        nh_=nh;
          cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel", 1);        
          
          linearSpeedMetresPerSec=0.1;
          angularSpeedDegreePerSeg=0.1;
    }
    
    bool moveForward(double distanceMeter)
    {
        int time_to_move=(int)round(fabs(distanceMeter/linearSpeedMetresPerSec));
		ros::Rate r(30);
 		int j=0;
                setAllZero();
                
		while(nh_.ok()){
			r.sleep();
			if(j==1){
     				if(distanceMeter>=0.0)
		      			base_cmd.linear.x= linearSpeedMetresPerSec;
				else
					base_cmd.linear.x= -linearSpeedMetresPerSec;
      			}
                        
                        if(j==1+time_to_move)
      			{
                            setAllZero();
    			}
                        
      			cmd_vel_pub_.publish(base_cmd);
      			j++;
			if(j>2+time_to_move)break;
		}
        
    }
    
    bool turnLeft(double angleDegree)
    {
        
    }
    
    void setAllZero()
    {
        base_cmd.linear.x=0;
        base_cmd.linear.y=0;
        base_cmd.linear.z=0;
        
        base_cmd.angular.x=0;
        base_cmd.angular.y=0;
        base_cmd.angular.z=0;
    }
};

#endif	/* MOVEROBOT_H */

