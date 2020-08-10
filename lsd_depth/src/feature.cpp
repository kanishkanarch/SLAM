#include<ros/ros.h>
#include<sensor_msgs/Image.h>
#include<vector>
#include<math.h>
using namespace std;

class SandP
{
       public:
               SandP()
               {
                       pub = nh.advertise<sensor_msgs::Image>("my_topic_feature", 1);
                       sub = nh.subscribe("my_topic_gray", 1, &SandP::callback, this);
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
		       my_msg.data = msg->data;                  //    COPYING REAL MESSAGE (ConstPtr& msg) TO LOCAL VARIABLE (my_msg) IS COMPLETED

                       
                       int px_cnt = 0;
                       int image[360][640];
                       for(int i = 0; i < 360; i++)              //    MAKING A 2D ARRAY TO DO FEATURE DETECTION IN
                       {
                             for(int j = 0; j < 640; j++)
                             {
                                       image[i][j] = my_msg.data[3*px_cnt];
                                      px_cnt ++;
                            }
                       }
    		       px_cnt = 1282;
                       int diff = 0;
    		       for(int i = 2; i < 358; i++)
		       {
			       for(int j = 2; j < 638; j++)
			       {
	  			       diff = 0;
   				       for(int c = -2; c < 2; c++)
   				       {
   					       if(abs(image[i][j] - image[i - 2][j + c]) > 10)
    					       {
  						       diff ++;
 					       }
     				       }
  				       for(int c = -2; c < 2; c++)
				       {
    					       if(abs(image[i][j] - image[i + 2][j + c]) > 10)
     					       {
     						       diff ++;
   					       }
   				       }
     				       for(int r = -1; r < 1; r++)
     				       {
  					       if(abs(image[i][j] - image[i + r][j - 1]) > 10)
					       {
 						       diff ++;
					       }
  				       }
     				       for(int r = -1; r < 1; r++)
  				       {
					       if(abs(image[i][j] - image[i + r][j + 1]) > 10)
					       {
						       diff ++;
					       }
				       }
				       if (diff > 4)
				       {
					       my_msg.data[3*px_cnt] = 0;
					       my_msg.data[3*px_cnt + 1] = 0;
					       my_msg.data[3*px_cnt + 2] = 255;
				       }
				       px_cnt ++;
			       }
			       px_cnt += 4;
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
	ros::init(argc, argv, "My_node_feature");
	SandP subandpub;
	ros::spin();
	return 0;
}

