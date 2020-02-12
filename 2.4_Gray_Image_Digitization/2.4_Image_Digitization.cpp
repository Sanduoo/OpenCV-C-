#include <iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;



int main(int argc,char* argv[])
{
    Mat img = imread("C:/1/1.jpg");
    if (img.empty())
        return -1;
    //namedWindow("img", WINDOW_AUTOSIZE);

    //显示彩色图像
    imshow("BGR", img);
    //分离通道
    vector<Mat> planes;
    split(img, planes);
    //显示B通道
    imshow("B", planes[0]);
    //显示G通道
    imshow("G", planes[1]);
    //显示R通道
    imshow("R", planes[2]);


    waitKey(0);
}

