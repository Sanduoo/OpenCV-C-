#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>

using namespace std;
using namespace cv;

class Mat2 {
	public:
		int Mat_use() {

			/*获得单通道Mat的基本信息*/
			//构造矩阵
			Mat m = (Mat_<int>(3, 2) << 1, 2, 3, 4, 5, 6);
			//矩阵的行列数
			cout << "行数:" << m.rows << endl;
			cout << "列数:" << m.cols << endl;
			//尺寸
			Size size = m.size();
			cout << "尺寸:" << size << endl;
			//通道数
			cout << "通道数:" << m.channels() << endl;
			//面积
			cout << "面积:" << m.total() << endl;
			//矩阵维数(单通道2维，多通道3维)
			cout << "维数:" << m.dims << endl;


			//利用at获取Mat对象中的值
			cout << "第2行第2列:" << m.at<int>(1, 1) << endl;

			//利用ptr返回的指针获取m中的值
			for (int r = 0; r < m.rows; r++) {
				const int* ptr = m.ptr<int>(r);
				for (int c = 0; c < m.cols; c++) {
					cout << ptr[c] << ",";
				}
				cout << endl;
			}
		
			//isContinuous可以判断每一行的值在内存中是否连续储存
			
			if (m.isContinuous()) {
				//得到矩阵m的第一个值的位置
				int* ptr = m.ptr<int>(0);
				//利用操作符"[]"取值
				for (int n = 0; n < m.rows * m.cols; n++) {
					cout << ptr[n] << ","<<endl;
				}
			}
			cout << "#########################" << endl;
			//利用成员变量step和data
			cout << m.step[0]<< endl;//8
			cout << m.step[1]<< endl;//4

			cout << *((int*)(m.data + m.step[0] * 1 + 1 * m.step[1])) << endl;

			//*(int*)  是强制转换后去指针指向变量的值

			/*
			二维矩阵
				step[0]——行的大小
				step[1]——元素的大小
			三维矩阵
				step[0]——面的大小
				step[1]——行的大小
				step[2]——元素的大小
			*/
			waitKey(0);
			return 0;
		}
};