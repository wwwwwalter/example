#include <iostream>
using namespace std;
#include "tcp.h"
#include <opencv2/opencv.hpp>
using namespace cv;



int main(void){

    cout << "hello,world" << endl;
    tcp();

    cv::Mat mat = cv::imread("C:/Users/study/Pictures/Screenshots/test.png");
    cv::Size size = cv::Size(int(mat.cols*0.3), int(mat.rows*0.5));
    cv::resize(mat,mat, size, cv::INTER_LINEAR);
    cout << mat.size << endl;
    cout << mat.channels() << endl;

    namedWindow("mat", WINDOW_AUTOSIZE);
    cv::imshow("mat",mat);
    cv::waitKey(0);

    return 0;
}