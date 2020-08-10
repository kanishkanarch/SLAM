#include<ros/ros.h>
#include<sensor_msgs/Image.h>
using namespace std;

class SandP
{
	public:
		SandP()
		{
			pub = nh.advertise<sensor_msgs::Image>("my_topic_gray", 1);
			sub = nh.subscribe("/ardrone/front/image_raw", 1, &SandP::callback, this);
		}
		void callback(const sensor_msgs::Image::ConstPtr& msg)
		{
			
			sensor_msgs::Image my_msg;
			my_msg.header.seq = msg->header.seq;      //    STARTED COPYING REAL MESSAGE (ConstPtr& msg) INTO LOCAL VARIABLE (my_msg)
			my_msg.header.stamp.sec = msg->header.stamp.sec;
			my_msg.header.stamp.nsec = msg->header.stamp.nsec;
			my_msg.header.frame_id = msg->header.frame_id;
			my_msg.height = msg->height;
			my_msg.width = msg->width;
			my_msg.encoding = msg->encoding;
			my_msg.is_bigendian = msg->is_bigendian;
			my_msg.step = msg->step;
			//my_msg.data.clear();
			my_msg.data = msg->data;                  //    COPYING REAL MESSAGE (ConstPtr& msg) TO LOCAL VARIABLE (my_msg) IS COMPLETED

			for(int i = 0; i < (my_msg.width*my_msg.height); i++)
			{
				my_msg.data[3*i] = (my_msg.data[3*i] + my_msg.data[3*i + 1] + my_msg.data[3*i + 2])/3;
				my_msg.data[3*i + 1] = my_msg.data[3*i + 2] = my_msg.data[3*i];
			}

			pub.publish(my_msg);
	}
	private:
		ros::NodeHandle nh;
		ros::Publisher pub;
		ros::Subscriber sub;
};

int main(int argc, char ** argv)
{
	ros::init(argc, argv, "My_node_gray");
	SandP subandpub;
	ros::spin();
	return 0;
}
