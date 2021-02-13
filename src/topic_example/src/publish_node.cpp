
#include <ros/ros.h>
#include "std_msgs/String.h" //use data struct of std_msgs/String  
#include "mbot_linux_serial.h"
#include<tf/transform_broadcaster.h>
#include<nav_msgs/Odometry.h>
#include<geometry_msgs/Twist.h>
#include<iostream>
using namespace std;
double l1;
double l2;
double l3;
void callback(const geometry_msgs::Twist& cmd_vel)
{
	ROS_INFO("Received a /cmd_vel message!");
	ROS_INFO("Linear Components:[%f,%f,%f]",cmd_vel.linear.x,cmd_vel.linear.y,cmd_vel.linear.z);
	l1=cmd_vel.linear.x*-100;l2=cmd_vel.linear.y*-1000;
	ROS_INFO("Angular Components:[%f,%f,%f]",cmd_vel.angular.x,cmd_vel.angular.y,cmd_vel.angular.z);
	l3=cmd_vel.angular.z*100;
	// Do velocity processing here:  
    // Use the kinematics of your robot to map linear and angular velocities into motor commands  
//    v_l = ...  
//    v_r = ...  
  
    // Then set your wheel speeds (using wheel_left and wheel_right as examples)  
//    wheel_left.set_speed(v_l)  
//    wheel_right.set_speed(v_r) 
}


//test send value
//double testSend1=l1;
double testSend2=2222.0;
unsigned char testSend3=0x07;

//test receive value
double testRece1=0.0;
double testRece2=0.0;
double testRece3=0.0;
unsigned char testRece4=0x00;

int main(int agrc,char **argv)
{
    ros::init(agrc,argv,"public_node");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("cmd_vel", 1000, callback);
    ros::Rate loop_rate(10);
    
    //串口初始化
    serialInit();

    while(ros::ok())
    {
        ros::spinOnce();
        //向STM32端发送数据，前两个为double类型，最后一个为unsigned char类型
	    writeSpeed(l1,l2,l3,testSend3);
        //从STM32接收数据，输入参数依次转化为小车的线速度、角速度、航向角（角度）、预留控制位
	    //readSpeed(testRece1,testRece2,testRece3,testRece4);
        //打印数据
	  //  ROS_INFO("%f,%f,%f,%d\n",l1,l2,testSend3,testRece4);
        loop_rate.sleep();
    }
    return 0;
}
 



