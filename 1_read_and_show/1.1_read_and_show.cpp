#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
#include<opencv2/highgui/highgui_c.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat src = imread("C:/1/1.jpg");
	if (src.empty()) {
		cout << "Can not find this file!" << endl;
		return -1;
	}
	namedWindow("opencv setup test", CV_WINDOW_AUTOSIZE);
	imshow("opencv setup test", src);

	Mat output;
	cvtColor(src, output, CV_BGR2BGRA);		//色彩空间转换
	namedWindow("output window", CV_WINDOW_AUTOSIZE);
	imshow("output windows", output);
	imwrite("C:/1/1.png", output);		//图像保存

	waitKey(0);
	return 0;

}