#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

class Mat_Operation {
public:
	Mat m1 = (Mat_<double>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	Mat m2 = (Mat_<double>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);


	int Add_1() {
		cout << "####Add_1####" << endl;
		Mat m3 = m1 + m2;
		for_1(m3);
		
		float value = 100;
		Mat m4 = m3 + value;
		for_1(m4);

		cout << "####Add_2####" << endl;
		Mat dst;
		add(m1, m2, dst, Mat(),CV_64FC1);
		for_1(dst);

		cout << "####Add_3####" << endl;
		Vec3f v1 = Vec3f(1, 2, 3);			//����Ҳ������ά�����ʱ�������
		Vec3f v2 = Vec3f(3, 2, 1);
		Vec3f v = v1 + v2;
		cout << v << endl;
		

		return 0;
	}

	int Substract_1() {
		cout << "####Substract_1####" << endl;
		Mat dst1 = m1 - m2;
		for_1(dst1);

		cout << "####Substract_2####" << endl;
		Mat dst2;
		subtract(m1, m2, dst2, Mat(), CV_64FC1);
		for_1(dst2);

		return 0;
	}

	int Point_Multiyply_1() {
		cout << "####Point_Multiyply_1####" << endl;
		Mat dst1 = m1.mul(m2);			//������
		for_1(dst1);

		
		cout << "####Point_Multiyply_2####" << endl;
		Mat dst2;
		multiply(m1, m2, dst2, 1.0, CV_64FC1);			//dst=m1*m2*sclae   ��m1��m2�������Ͳ�����ͬ
		for_1(dst2);

		return 0;
	}

	int Point_Divide_1() {
		cout << "####Point_Divide_1####" << endl;
		Mat dst1 = m1 / m2;
		for_1(dst1);

		return 0;
	}

	Mat src1 = (Mat_<double>(3, 3) << 1,2,3,4,5,6,7,8,9);
	Mat src2 = (Mat_<double>(3, 3) << 9,8,7,6,5,4,3,2,1);

	int Multiyply_1() {
		cout << "####��ͨ���������####" << endl;
		Mat dst1 = src1 * src2;				//�������Ҫ�������float��double
		for_1(dst1);

		cout << "####˫ͨ���������####" << endl;
		Mat mm1 = (Mat_<Vec2f>(2, 1) << Vec2f(1, 2), Vec2f(3, 4));
		Mat mm2 = (Mat_<Vec2f>(1, 2) << Vec2f(4,3), Vec2f(2,1));
		Mat mm3 = mm1 * mm2;		
		/*
		����ʱ����Vec2f����һ������
		1+2i					-2+11i	0+5i		[-2,11],[0,5],
		3+4i	*	4+3i 2+i=	 0+15i	2+24i	=	[0,25],[2,11]
		*/
		for_2(mm3);

		cout << "####gemm-generalized matrix multiplication	����˷�####" << endl;
		/*gemm(src1,src2,alpha,src3,beta,dst,flags)
		alpha:src1��src2��˺��ϵ����
		beta��src3��ϵ����
		flags�� 0-�����䣬
				GEMM_1_T-src1ת��,
				GEMM_2_T-src2ת��,
				GEMM_3_T-src3ת��

				�����ʹ�ã�GEMM_1_T+GEMM_2_T
		*/
		Mat dst2;
		gemm(src1, src2, 1, NULL, 0, dst2, 0);
		for_1(dst2);
		return 0;
	}

	int Others() {
		cout << "####��ָ����####" << endl;
		Mat dst;
		pow(m2, 2, dst);
		for_1(dst);

		return 0;
	}


	int for_1(Mat m) {
		for (int r = 0; r < m.rows; r++) {
			for (int c = 0; c < m.cols; c++) {
				cout << m.at<double>(r, c) << ",";
			}
			cout << endl;
		}
		return 0;
	}



	int for_2(Mat m) {
		for (int r = 0; r < m.rows; r++) {
			for (int c = 0; c < m.cols; c++) {
				cout << m.at<Vec2f>(r, c) << ",";
			}
			cout << endl;
		}
		return 0;
	}
};