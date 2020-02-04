#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat src = imread("C:/1/1.jpg");
	if (src.empty()) {
		cout << "Can not find this file!" << endl;
		return -1;
	}
	namedWindow("original image", CV_WINDOW_AUTOSIZE);
	imshow("original image", src);

	/*利用Mat创造一张纯色图片*/
	Mat dst;
	dst = Mat(src.size(), src.type());
	dst = Scalar(0, 0, 255);	//将图像设置成单一灰度和颜色,Scalar(B,G,R)
	namedWindow("Scalar image", CV_WINDOW_AUTOSIZE);
	imshow("Scalar image", dst);

	/*copyTo(roi , mask)函数*/
	Mat copy_dst;
	src.copyTo(copy_dst);
	//namedWindow("coyp_image", CV_WINDOW_AUTOSIZE);
	imshow("copy_image", copy_dst);

	/*
	cvtColor(src,dst,CV_BGR2GRAY);
	*/

	/*宽高*/
	int col = dst.cols;
	int row = dst.rows;
	const uchar* firstRow = src.ptr<uchar>(1);
	printf("col:%d\n row:%d\n first_pixel_value:%d\n", col, row, *firstRow);

	Mat m(100, 200, CV_8UC1, Scalar(1));
	//imshow("cv_8uc1_image", m);

	Mat m1;
	m1.create(src.size(), src.type());
	m1 = Scalar(0, 255, 0);

	Mat m2;
	Mat kernal = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	/*
	void filter2D( InputArray src, OutputArray dst, int ddepth,
							InputArray kernel, Point anchor = Point(-1,-1),
							double delta = 0, int borderType = BORDER_DEFAULT );

	src：源图像Mat对象
	dst：目标图像Mat对象
	ddepth：目标图像的深度，一般填-1即可，表示源图像与目标图像深度相同。
	kernel：卷积核,一个单通道浮点型矩阵。如果想在图像不同的通道使用不同的kernel，可以先使用split()函数将图像通道事先分开。
	anchor：内核的基准点，其默认值为(-1,-1)说明位于kernel的中心位置。基准点即kernel中与进行处理的像素点重合的点，不填即默认值。
	delta ：在储存目标图像前可选的添加到像素的值，默认值为0，不填就是默认值。
	borderType ：像素向外逼近的方法，默认值是BORDER_DEFAULT,即对全部边界进行计算，不填就是默认。


	*/
	filter2D(src, m2, -1, kernal);
	imshow("m2", m2);

	Mat m3 = Mat::zeros(src.size(), src.type());
	Mat m4 = Mat::ones(20, 20, CV_8UC3); // Mat m = Mat(2, 2, CV_8UC3, 1);

	imshow("m3", m3);
	imshow("m4", m4);


	waitKey(0);
	return 0;
}