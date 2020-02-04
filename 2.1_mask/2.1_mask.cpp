#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
#include<opencv2/highgui/highgui_c.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat src = imread("C:/1/20200204.jpg");
	if (src.empty() ){
		cout << "Can not find this file!" << endl;
		return -1;
	}
	namedWindow("original image", CV_WINDOW_AUTOSIZE);
	imshow("original image", src);

	Mat mask_result;
	//src.copyTo(mask_result);

	int nchannels = src.channels();
	int heigh = src.rows;		//深度Y
	int cols = src.cols;		//通道，一般灰度为1，彩色图为3（RGB），A通道——alpha通道透明度
	int width = (src.cols-1) * nchannels;		//宽度X
	mask_result = Mat::zeros(src.size(), src.type());

	/*
		灰度图像：
			→col
	   row↓L00	L01	L02
			L10	L11	L12
			L20	L21	L22


		RGB图像：(通道为BGR排列)
			→col
	   row↓B00	G00	R00		B01	G01	R01


			B10	G10	R10		B11	G11	R11
	*/

	for (int row = 1; row < heigh - 1; row++) {
		const uchar* prev = src.ptr<uchar>(row - 1);
		const uchar* current = src.ptr<uchar>(row);
		const uchar* next = src.ptr<uchar>(row + 1);
		uchar* output = mask_result.ptr<uchar>(row);

		for (int col = 1; col < width - 1; col++) {
			/*
			0	-1	0
			-1	5	-1
			0	-1	0
			*/
			*output = saturate_cast<uchar>(5 * current[col] - prev[col] - next[col] - current[col - nchannels] - current[col + nchannels]);
										  //5*(1,1)			-1*(0,1)	-1*(2,1)	-1*(1,0)				   -1*(1,2)
			output++;
		}
	}

	namedWindow("mask image", CV_WINDOW_AUTOSIZE);
	imshow("mask image", mask_result);


	waitKey(0);
	return 0;

}