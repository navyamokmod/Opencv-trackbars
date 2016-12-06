#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

//cvtColor (inputMatvariable,outputMatvariable,---)
						//
					//(CV_RGB2GRAY)
					//(CV_BGR2HSV)
					//(CV_HSV2BGR)
using namespace cv;
using namespace std;
int main (){
		Mat var=imread("life.jpg",1);

		Mat var2(var.rows,var.cols,CV_8UC1,Scalar(0));
			
			
		int z;
		z=68;
		namedWindow("flags", WINDOW_AUTOSIZE);
		createTrackbar("var", "flags", &z, 255);
		
		while(1){

			for(int i=0;i<var.rows;i++)
		{		


			for(int j=0;j<var.cols;j++)
			{	int l=var.at<Vec3b> (i,j)[0];
                              	int m=var.at<Vec3b> (i,j)[1];
                              	int n=var.at<Vec3b> (i,j)[2];

				var2.at<uchar>(i,j)=l+m+n/3;

				if(var2.at<uchar>(i,j)<z)
					var2.at<uchar>(i,j)=0;
				else
					var2.at<uchar>(i,j)=255;}}

				imshow("flags",var2);
				waitKey(20);
				
		
}
return 0;
}
