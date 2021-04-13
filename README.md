# catkin_rplidar
硬件设备为intel nuc,思岚-a1/a2;usb to ttl；软件ubuntu-16.04 ros-kinetic;
 物流小车激光雷达方案，该方案为接触激光雷达与ROS后的初次实验，存在许多问题但对我个人来说具有学习和纪念意义。
laser_scan_matcher为雷达扫描匹配的一个功能包，由于初次使用ROS完成项目当时还未接触对于底层IMU与轮速计部分的通信故采用此功能包来实现里程计数据的模拟。运行命令为roslaunch demo_gmapping_A1.launch
learning_service为学习ROS所创建的功能包
mrobot_bringup、mrobot_description、mrobot_gazebo、mrobot_teleop等为《ROS机器人开发实践》中配套源码，并未使用
mrobot_navigation为导航功能包启动命令为 roslaunch nav_demo,该文件为自行编写的，主要涉及导航地图文件的选择、激光雷达启动、启动激光匹配增量功能包、坐标变换等
topic_example为上位机与底盘控制板通信功能包，运行命令为rosrun topic_example publish_node，可根据使用需要修改
由于初次接触ROS该项目存在诸多不足，在后续的AGV工业小车项目中方案与代码会更加成熟


该项目下载后不可直接编译，可根据需要将src下的功能包模块移入自己的工作空间后，执行catkin_make即可

error:
1.No rule to make target '/usr/lib/x86_64-linux-gnu/libproj.so 
sudo ln -s  /usr/lib/x86_64-linux-gnu/libproj.so.9 /usr/lib/x86_64-linux-gnu/libproj.so 
如果文件夹内部没有此库，需要终端敲sudo apt-get install libproj-dev  ，安装即可！
