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

		Mat var1(var.rows,var.cols,CV_8UC3,Scalar(0,0,0));
		
		
			
		int satr,satg,satb,tolr,tolg,tolb;
		
		satr=50;
		satg=50;
		satb=50;
		tolr=10;tolg=10;tolb=10;
		namedWindow("flags", WINDOW_AUTOSIZE);
		namedWindow("flags1", WINDOW_AUTOSIZE);
		createTrackbar("Red", "flags1", &satr, 255);
		createTrackbar("Green","flags1", &satg, 255);
		createTrackbar("Blue", "flags1", &satb, 255);
		createTrackbar("tolRed", "flags1", &tolr, 255);
		createTrackbar("tolGreen","flags1", &tolg, 255);
		createTrackbar("tolBlue", "flags1", &tolb, 255);
		
		while(1){

			for(int i=0;i<var.rows;i++)
		{		


			for(int j=0;j<var.cols;j++)
			{int l= var.at<Vec3b>(i,j)[0];
			int m= var.at<Vec3b>(i,j)[1];
			int n= var.at<Vec3b>(i,j)[2];

				if(l<satb+tolb && l>satb-tolb)
					var1.at<Vec3b>(i,j)[0]=255;
				else
					var1.at<Vec3b>(i,j)[0]=0;
				
				if(m<satg+tolg && m>satg-tolg)
					var1.at<Vec3b>(i,j)[1]=255;
				else
					var1.at<Vec3b>(i,j)[1]=0;
							

				if(n<satr+tolr && n>satr-tolr)
					var1.at<Vec3b>(i,j)[2]=255;
				else
					var1.at<Vec3b>(i,j)[2]=0;
				
}
				

}

				imshow("flags",var1);
				waitKey(20);
				
		
}
return 0;
}
