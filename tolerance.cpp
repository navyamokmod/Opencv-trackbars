#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main(int count,char *arg[])
{
  int red,blue,green,rt,bt,gt;
  bool c1,c2,c3;
  Mat inp=imread(arg[1],1);
  Mat op(inp.rows,inp.cols,CV_8UC3,Scalar(255,255,255));
  namedWindow("image_extractor",WINDOW_AUTOSIZE);
  namedWindow("input",WINDOW_AUTOSIZE);
  //namedWindow("image_extractor",WINDOW_AUTOSIZE);
  createTrackbar("red","image_extractor",&red,255);
  createTrackbar("blue","image_extractor",&blue,255);
  createTrackbar("green","image_extractor",&green,255);
  createTrackbar("red_tolerance","image_extractor",&rt,100);
  createTrackbar("blue_tolerance","image_extractor",&bt,100);
  createTrackbar("green_tolerance","image_extractor",&gt,100);
  while(1)
  {
      for(int i=0;i<inp.rows;++i)
	for(int j=0;j<inp.cols;++j)
	  {
	    c1=inp.at<Vec3b>(i,j).val[0] < blue*(100+bt)/100 && inp.at<Vec3b>(i,j).val[0] > blue*(100-bt)/100;
	    c2=inp.at<Vec3b>(i,j).val[1] < green*(100+gt)/100 && inp.at<Vec3b>(i,j).val[1] > green*(100-gt)/100;
	    c3=inp.at<Vec3b>(i,j).val[2] < red*(100+rt)/100 && inp.at<Vec3b>(i,j).val[2] > red*(100-rt)/100;
	    if(c1 && c2 && c3)
	      {
		op.at<Vec3b>(i,j)[0]=inp.at<Vec3b>(i,j)[0];
		op.at<Vec3b>(i,j)[1]=inp.at<Vec3b>(i,j)[1];
		op.at<Vec3b>(i,j)[2]=inp.at<Vec3b>(i,j)[2];
	      }
	    else
	      {
		op.at<Vec3b>(i,j)[0]=255;
		op.at<Vec3b>(i,j)[1]=255;
		op.at<Vec3b>(i,j)[2]=255;
	      }
	  }
      imshow("input",inp);
      imshow("image_extractor",op);
      waitKey(10);
      }
  waitKey(0);
  return 0;
}
