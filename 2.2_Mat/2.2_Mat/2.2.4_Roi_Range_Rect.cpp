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
		//使用row和col获取矩阵的第i行第j列
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

	/*在使用rowRange和colRange、Rect时，roi矩阵是指向原矩阵的，修改roi后原矩阵也会发生变化*/
	//选择矩形区域
	int Rect_1() {
		Mat roi1 = m(Rect(Point(1, 1), Point(3, 3)));	//左上角和右下角的坐标
		Mat ro2 = m(Rect(2, 2, 2, 2));					//x，y，宽，高
		Mat roi3 = m(Rect(Point(2,1),Size(2,2)));		//左上角的坐标，尺寸
		Mat roi4 = m(Rect(2, 2, 2, 2)).clone();			//使用clone不需要指向原矩阵

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