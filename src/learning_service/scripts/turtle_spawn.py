import sys
import rospy
from turtlesim.srv import Spawn
def turtle_spawn():
	rospy.init_node('turtlr_spawn')
	rospy.wait_for_service('/spawn')
	try:
		add_turtle = rospy.ServiceProxy('/spawn',Spawn)
		response=add_turtle(2.0,2.0,0.0,"turtle2")
		return response.name
	except rospy.ServiceException,e;
		print("service call failed:%s"%e)
if __name__=="__main__":
	print("spawn turtle successfully [name:%s]"%(turtle_spawn())
