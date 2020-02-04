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

	/*����Mat����һ�Ŵ�ɫͼƬ*/
	Mat dst;
	dst = Mat(src.size(), src.type());
	dst = Scalar(0, 0, 255);	//��ͼ�����óɵ�һ�ҶȺ���ɫ,Scalar(B,G,R)
	namedWindow("Scalar image", CV_WINDOW_AUTOSIZE);
	imshow("Scalar image", dst);

	/*copyTo(roi , mask)����*/
	Mat copy_dst;
	src.copyTo(copy_dst);
	//namedWindow("coyp_image", CV_WINDOW_AUTOSIZE);
	imshow("copy_image", copy_dst);

	/*
	cvtColor(src,dst,CV_BGR2GRAY);
	*/

	/*���*/
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

	src��Դͼ��Mat����
	dst��Ŀ��ͼ��Mat����
	ddepth��Ŀ��ͼ�����ȣ�һ����-1���ɣ���ʾԴͼ����Ŀ��ͼ�������ͬ��
	kernel�������,һ����ͨ�������;����������ͼ��ͬ��ͨ��ʹ�ò�ͬ��kernel��������ʹ��split()������ͼ��ͨ�����ȷֿ���
	anchor���ں˵Ļ�׼�㣬��Ĭ��ֵΪ(-1,-1)˵��λ��kernel������λ�á���׼�㼴kernel������д�������ص��غϵĵ㣬���Ĭ��ֵ��
	delta ���ڴ���Ŀ��ͼ��ǰ��ѡ����ӵ����ص�ֵ��Ĭ��ֵΪ0���������Ĭ��ֵ��
	borderType ����������ƽ��ķ�����Ĭ��ֵ��BORDER_DEFAULT,����ȫ���߽���м��㣬�������Ĭ�ϡ�


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