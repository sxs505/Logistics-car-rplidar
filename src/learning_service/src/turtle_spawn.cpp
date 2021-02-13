#include<ros/ros.h>
#include<turtlesim/Spawn.h>
int main(int argc,char** argv)
{
//初始化ROS节点
ros::init(argc,argv,"turtle_spawn");
//创建节点句柄
ros::NodeHandle node;
//创建一个服务客户端
ros::service::waitForService("/spawn");
ros::ServiceClient add_turtle=node.serviceClient<turtlesim::Spawn>("/spawn");

turtlesim::Spawn srv;
srv.request.x=2.0;
srv.request.y=2.0;
srv.request.name="turtle2";
ROS_INFO("call service to spwan turtle[x:%0.6f,y:%0.6f,name:#s]",srv.request.x,srv.request.y,srv.request.name.c_str());
add_turtle.call(srv);
ROS_INFO("Spwan turtle successfully [name:%s]",srv.response.name.c_str());
return 0;
};

