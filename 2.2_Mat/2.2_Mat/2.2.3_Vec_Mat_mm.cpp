#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<opencv2/core/core.hpp>
#include<vector>

using namespace std;
using namespace cv;

class Vec_1 {
public:
	int Vec_def() {
		
		//Vec构造列向量,Vec<Typename,int_cn>(  ,  ,  ....)    cn为行数
		Vec<int, 3> vi(21, 22, 23);
		cout << "向量的行数：" << vi.rows << endl;
		cout << "向量的列数：" << vi.cols << endl;

		cout << "访问向量第0个元素：" << vi[0] << endl;
		cout << "访问向量第2个元素：" << vi[2] << endl;

		waitKey (0);
		return 0;
	}
};

/*单通道矩阵的每一个元素都是一个值，多通道矩阵的每一个元素都可以看作一个向量（多层色彩组合叠加）*/

class Mat_mm {
	public:
		int Mat_def_use() {
			//def____Mat(int roes,int cols,CV_32FC(n))
			
			Mat mm = (Mat_<Vec3f>(2, 2)<< Vec3f(1, 10, 100),Vec3f(2, 20, 20),Vec3f(3, 30, 30), Vec3f(4, 40, 40));
			/*
			1,10,100	2,20,20
			3,30,30		4,40,40
			*/

			//利用at
			cout << "######at######" << endl;
			for (int r = 0; r < mm.rows; r++) {
				for (int c = 0; c < mm.cols; c++) {
					//打印第r行dic列的元素值
					cout << mm.at<Vec3f>(r, c) << ",";
				}
				cout << endl;
			}
		
			//利用ptr
			cout << "######ptr######" << endl;
			for (int r = 0; r < mm.rows; r++) {
				Vec3f* ptr = mm.ptr<Vec3f>(r);
				for (int c = 0; c < mm.cols; c++) {
					cout << ptr[c] << ",";
				}
				cout << endl;
			}

			//利用isContinuous和ptr
			cout << "######isContinuous和ptr######" << endl;
			if (mm.isContinuous()) {
				Vec3f* ptr = mm.ptr<Vec3f>(0);	//指向多通道矩阵的第一个元素的指针
				for (int n = 0; n < mm.cols; n++) {
					cout << ptr[n] << endl;
				}
			}

			//利用data和step
			cout << "######data和step######" << endl;
			for (int r = 0; r < mm.rows; r++) {
				for (int c = 0; c < mm.cols; c++) {
					Vec3f* ptr = (Vec3f*)(mm.data + r * mm.step[0] + c * mm.step[1]);
					cout << *ptr << ",";
				}
				cout << endl;
			}


			/*通道分离——多通道矩阵中的向量的第一个值组成一个单通道矩阵，一次类推*/
			cout << "######split和vector######" << endl;
			vector<Mat> planes;		//储存单通道矩
			split(mm, planes);		 //分离多通道矩阵
			
			Mat mm1 = planes.at(0);
			Mat mm2 = planes.at(1);
			Mat mm3 = planes.at(2);

			for_at(mm1);
			for_at(mm2);
			for_at(mm3);


			//合并通道，与分离通道同理
			cout << "######merge1数组######" << endl;
			/*第一种储存在数组中*/
			Mat plane1[] = { mm1,mm2,mm3 };
			Mat mat1;
			merge(plane1,3, mat1);
			for_at(mat1);

			/*第二种储存在vector容器其中*/
			cout << "######merge2容器######" << endl;
			vector<Mat> plane2;
			plane2.push_back(mm1);
			plane2.push_back(mm2);
			plane2.push_back(mm3);
			Mat mat2;
			merge(plane2, mat2);
			for_at(mat2);

			/*
			######merge1数组######
			1,10,
			3,30,
			######merge2容器######
			1,10,
			3,30,
			*/

			waitKey(0);
			return 0;
		}

		int for_at(Mat mat) {
			for (int r = 0; r < mat.rows; r++) {
				for (int c = 0; c < mat.cols; c++) {
					//打印第r行dic列的元素值
					cout << mat.at<float>(r, c) << ",";
				}
				cout << endl;
			}

			return 0;
		}
};