#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<std_srvs/Trigger.h>
ros::Publisher turtle_vel_pub;
bool pubCommand=false;
bool commandCallback(std_srvs::Trigger::Request &req,std_srvs::Trigger::Response &res)
{
pubCommand=!pubCommand;
//显示请求数据
ROS_INFO("publish turtle velocity command [%s]",pubCommand==true?"yes":"no");
//设置反馈数据
res.success =true;
res.message="chang turtle command state!";
return true;
}
int main(int argc,char **argv)
{
//初始化ROS节点
ros::init(argc,argv,"turtle_command_server");
//创建节点句柄
ros::NodeHandle n;
ros::ServiceServer command_service=n.advertiseService("/turtle_command",commandCallback);
turtle_vel_pub=n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
ROS_INFO("ready to receive turtle command.");
ros::Rate loop_rate(10);
while(ros::ok())
{
ros::spinOnce();
if (pubCommand)
{geometry_msgs::Twist vel_msg;
vel_msg.linear.x=0.5;
vel_msg.angular.z=0.2;
turtle_vel_pub.publish(vel_msg);
}
loop_rate.sleep();
}
return 0;
}

