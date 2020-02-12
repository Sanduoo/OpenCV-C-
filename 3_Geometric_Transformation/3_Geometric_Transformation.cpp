#include <iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int for_out(Mat);

int main(int argc, char* argv[])
{
	/*3.1.4计算仿射矩阵*/
	Mat src1 = (Mat_<float>(3, 2) << 0, 0, 200, 0, 0, 200);
    Mat src2 = (Mat_<float>(3, 2) << 0, 0, 100, 0, 0, 100);

	cout << "计算仿射矩阵:方程法-getAffineTransform()" << endl;
    Mat A = getAffineTransform(src1, src2);
	for_out(A);

	cout << "计算仿射矩阵:矩阵法" << endl;
	Mat s = (Mat_<double>(3, 3) << 0.5, 0, 0, 0, 0.5, 0, 0, 0, 1);	//缩放矩阵
	Mat t = (Mat_<double>(3, 3) << 1, 0, 100, 0, 1, 200, 0, 0, 1);	//平移矩阵
	Mat B;
	gemm(s, t, 1.0, Mat(), 0, B,0);
	for_out(B);

	cout << "getRotationMatrix2D" << endl;
	//等比例缩放仿射变换-getRotationMatrix2D(center-中心坐标, angle-角度-负顺正逆, scale-缩放系数)
	Mat C = getRotationMatrix2D(Point2d(40, 50), 30, 0.5);
	for_out(C);

	/*3.1.5插值算法
	最近临插值法（有锯齿状）
	双线性插值
	三次抽条插值
	*/
	Mat I = imread("C:/1/1.jpg");
	if (!I.data)
		return -1;
	/*1、使用warpAffine缩放*/
	//缩放仿射矩阵，等比例缩小两倍
	Mat s1= (Mat_<float>(2, 3) << 0.5, 0, 0, 0, 0.5, 0);
	Mat dst1;
	warpAffine(I, dst1, s1, Size(I.cols / 2, I.rows / 2), 0.5, 0.5);

	/*2、使用resize等比例缩小2倍*/
	Mat dst2;
	resize(I, dst2, Size(), 0.5, 0.5);

	namedWindow("原图", CV_WINDOW_AUTOSIZE);
	imshow("原图", I);
	imshow("warpAffine", dst1);
	imshow("resize", dst2);

	waitKey(0);
	return 0;
}

int for_out(Mat m) {
	for (int r = 0; r < m.rows; r++) {
		for (int c = 0; c < m.cols; c++) {
			cout << m.at<double>(r, c) << ",";
		}
		cout << endl;
	}
	return 0;
}