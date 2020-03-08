#include <iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

Mat clac_GrayHist(const Mat& image);
int for_out(Mat);

int main(int argc,char* argv)
{
    Mat src  = imread("C:/1/1.jpg");
    imshow("src", src);
    Mat dst;

    dst = clac_GrayHist(src);
    if (dst.empty())
        return -1;
    imwrite("C:/1/grayhist.jpg", dst);
    for_out(dst);

    waitKey(0);
    return 0;
}

Mat clac_GrayHist(const Mat & image)
{
    //储存256个灰度级的像素个数
    Mat histgram = Mat::zeros(Size(256, 1), CV_32SC1);
    int row = image.rows;
    int col = image.cols;
    //计算每个灰度级的个数
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            int index = int(image.at<uchar>(r, c));
            histgram.at<int>(0, index) += 1;
        }
    }
    return histgram;
}

int for_out(Mat m) {
    for (int r = 0; r < m.rows; r++) {
        for (int c = 0; c < m.cols; c++) {
            cout << m.at<int>(r, c) << ",";
        }
        cout << endl;
    }
    return 0;
}