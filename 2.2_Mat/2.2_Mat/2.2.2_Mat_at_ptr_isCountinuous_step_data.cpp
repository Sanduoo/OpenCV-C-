#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>

using namespace std;
using namespace cv;

class Mat2 {
	public:
		int Mat_use() {

			/*��õ�ͨ��Mat�Ļ�����Ϣ*/
			//�������
			Mat m = (Mat_<int>(3, 2) << 1, 2, 3, 4, 5, 6);
			//�����������
			cout << "����:" << m.rows << endl;
			cout << "����:" << m.cols << endl;
			//�ߴ�
			Size size = m.size();
			cout << "�ߴ�:" << size << endl;
			//ͨ����
			cout << "ͨ����:" << m.channels() << endl;
			//���
			cout << "���:" << m.total() << endl;
			//����ά��(��ͨ��2ά����ͨ��3ά)
			cout << "ά��:" << m.dims << endl;


			//����at��ȡMat�����е�ֵ
			cout << "��2�е�2��:" << m.at<int>(1, 1) << endl;

			//����ptr���ص�ָ���ȡm�е�ֵ
			for (int r = 0; r < m.rows; r++) {
				const int* ptr = m.ptr<int>(r);
				for (int c = 0; c < m.cols; c++) {
					cout << ptr[c] << ",";
				}
				cout << endl;
			}
		
			//isContinuous�����ж�ÿһ�е�ֵ���ڴ����Ƿ���������
			
			if (m.isContinuous()) {
				//�õ�����m�ĵ�һ��ֵ��λ��
				int* ptr = m.ptr<int>(0);
				//���ò�����"[]"ȡֵ
				for (int n = 0; n < m.rows * m.cols; n++) {
					cout << ptr[n] << ","<<endl;
				}
			}
			cout << "#########################" << endl;
			//���ó�Ա����step��data
			cout << m.step[0]<< endl;//8
			cout << m.step[1]<< endl;//4

			cout << *((int*)(m.data + m.step[0] * 1 + 1 * m.step[1])) << endl;

			//*(int*)  ��ǿ��ת����ȥָ��ָ�������ֵ

			/*
			��ά����
				step[0]�����еĴ�С
				step[1]����Ԫ�صĴ�С
			��ά����
				step[0]������Ĵ�С
				step[1]�����еĴ�С
				step[2]����Ԫ�صĴ�С
			*/
			waitKey(0);
			return 0;
		}
};