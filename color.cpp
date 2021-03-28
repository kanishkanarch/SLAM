// Partly inspired from https://gist.github.com/PrieureDeSion/77c109a074573ce9d13da244e5f82c4d
#include<ros/ros.h>
#include<sensor_msgs/Image.h>
#include<vector>
using namespace std;

class SandP
{
	public:
		SandP()
		{
			pub = nh.advertise<sensor_msgs::Image>("my_topic", 1);
			sub = nh.subscribe("/ardrone/front/image_raw", 1, &SandP::callback, this);
		}
		void callback(const sensor_msgs::Image::ConstPtr& msg)
		{
			
			sensor_msgs::Image my_msg;

			int arr_RGB[360][640][3];
/*			vector <int> R;
			vector <int> G;
			vector <int> B;
*/
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
			
/*			for(int i = 0; i < 360*640; i++)
			{
				R.push_back(my_msg.data[3*i]);
				G.push_back(my_msg.data[3*i+ 1]);
				B.push_back(my_msg.data[3*i+ 2]);
			}		
*/
			int count = 0;                               //    SEPARATING ALL THREE COLORS FROM my_msg TO arr_RGB[][][]
			for(int i = 0; i < 360; i++)
			{
				for(int j = 0; j < 640; j++)
				{
					arr_RGB[i][j][0] = my_msg.data[3*count];
					arr_RGB[i][j][1] = my_msg.data[3*count + 1];
					arr_RGB[i][j][2] = my_msg.data[3*count + 2];
							
					count ++;
				}
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
	ros::init(argc, argv, "My_node");
	SandP subandpub;
	ros::spin();
	return 0;
}
