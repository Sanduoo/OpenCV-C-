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
		
		//Vec����������,Vec<Typename,int_cn>(  ,  ,  ....)    cnΪ����
		Vec<int, 3> vi(21, 22, 23);
		cout << "������������" << vi.rows << endl;
		cout << "������������" << vi.cols << endl;

		cout << "����������0��Ԫ�أ�" << vi[0] << endl;
		cout << "����������2��Ԫ�أ�" << vi[2] << endl;

		waitKey (0);
		return 0;
	}
};

/*��ͨ�������ÿһ��Ԫ�ض���һ��ֵ����ͨ�������ÿһ��Ԫ�ض����Կ���һ�����������ɫ����ϵ��ӣ�*/

class Mat_mm {
	public:
		int Mat_def_use() {
			//def____Mat(int roes,int cols,CV_32FC(n))
			
			Mat mm = (Mat_<Vec3f>(2, 2)<< Vec3f(1, 10, 100),Vec3f(2, 20, 20),Vec3f(3, 30, 30), Vec3f(4, 40, 40));
			/*
			1,10,100	2,20,20
			3,30,30		4,40,40
			*/

			//����at
			cout << "######at######" << endl;
			for (int r = 0; r < mm.rows; r++) {
				for (int c = 0; c < mm.cols; c++) {
					//��ӡ��r��dic�е�Ԫ��ֵ
					cout << mm.at<Vec3f>(r, c) << ",";
				}
				cout << endl;
			}
		
			//����ptr
			cout << "######ptr######" << endl;
			for (int r = 0; r < mm.rows; r++) {
				Vec3f* ptr = mm.ptr<Vec3f>(r);
				for (int c = 0; c < mm.cols; c++) {
					cout << ptr[c] << ",";
				}
				cout << endl;
			}

			//����isContinuous��ptr
			cout << "######isContinuous��ptr######" << endl;
			if (mm.isContinuous()) {
				Vec3f* ptr = mm.ptr<Vec3f>(0);	//ָ���ͨ������ĵ�һ��Ԫ�ص�ָ��
				for (int n = 0; n < mm.cols; n++) {
					cout << ptr[n] << endl;
				}
			}

			//����data��step
			cout << "######data��step######" << endl;
			for (int r = 0; r < mm.rows; r++) {
				for (int c = 0; c < mm.cols; c++) {
					Vec3f* ptr = (Vec3f*)(mm.data + r * mm.step[0] + c * mm.step[1]);
					cout << *ptr << ",";
				}
				cout << endl;
			}


			/*ͨ�����롪����ͨ�������е������ĵ�һ��ֵ���һ����ͨ������һ������*/
			cout << "######split��vector######" << endl;
			vector<Mat> planes;		//���浥ͨ����
			split(mm, planes);		 //�����ͨ������
			
			Mat mm1 = planes.at(0);
			Mat mm2 = planes.at(1);
			Mat mm3 = planes.at(2);

			for_at(mm1);
			for_at(mm2);
			for_at(mm3);


			//�ϲ�ͨ���������ͨ��ͬ��
			cout << "######merge1����######" << endl;
			/*��һ�ִ�����������*/
			Mat plane1[] = { mm1,mm2,mm3 };
			Mat mat1;
			merge(plane1,3, mat1);
			for_at(mat1);

			/*�ڶ��ִ�����vector��������*/
			cout << "######merge2����######" << endl;
			vector<Mat> plane2;
			plane2.push_back(mm1);
			plane2.push_back(mm2);
			plane2.push_back(mm3);
			Mat mat2;
			merge(plane2, mat2);
			for_at(mat2);

			/*
			######merge1����######
			1,10,
			3,30,
			######merge2����######
			1,10,
			3,30,
			*/

			waitKey(0);
			return 0;
		}

		int for_at(Mat mat) {
			for (int r = 0; r < mat.rows; r++) {
				for (int c = 0; c < mat.cols; c++) {
					//��ӡ��r��dic�е�Ԫ��ֵ
					cout << mat.at<float>(r, c) << ",";
				}
				cout << endl;
			}

			return 0;
		}
};