#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

class Roi {
public:
	Mat m = (Mat_<int>(3,3) << 1, 2, 3, 4,5,6,7,8,9);
	int Row_Col() {
		//ʹ��row��col��ȡ����ĵ�i�е�j��
		int r = 1;
		int j = 0;
		Mat mr = m.row(r);
		Mat mc = m.col(j);

		return 0;
	}

	int Range_1() {
		Mat r_range = m.rowRange(Range(1, 3));
		r_range.at<int>(0,0) = 100;
		for_1(r_range);
		for_1(m);
		return 0;
	}

	int clone_copyTo() {
		Mat mm = m.rowRange(1, 3).clone();
		Mat mmm;
		m.rowRange(1, 3).copyTo(mmm);
		for_1(mm);
		for_1(mmm);

		return 0;
	}

	/*��ʹ��rowRange��colRange��Rectʱ��roi������ָ��ԭ����ģ��޸�roi��ԭ����Ҳ�ᷢ���仯*/
	//ѡ���������
	int Rect_1() {
		Mat roi1 = m(Rect(Point(1, 1), Point(3, 3)));	//���ϽǺ����½ǵ�����
		Mat ro2 = m(Rect(2, 2, 2, 2));					//x��y������
		Mat roi3 = m(Rect(Point(2,1),Size(2,2)));		//���Ͻǵ����꣬�ߴ�
		Mat roi4 = m(Rect(2, 2, 2, 2)).clone();			//ʹ��clone����Ҫָ��ԭ����

		return 0;
	}

	int for_1(Mat m) {
		for (int r = 0; r < m.rows; r++) {
			for (int c = 0; c < m.cols; c++) {
				cout << m.at<int>(r, c) << ",";
			}
			cout << endl;
		}
		return 0;
	}
};