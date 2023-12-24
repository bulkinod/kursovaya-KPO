#include "header.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include "header.h"
#include <fstream>
#include <string>
using namespace cv;
using namespace std;

// ���������� ����������� � �������� �� ������������
bool CheckFormat(String image, Mat &source) {

	source = imread(image);
	if (source.empty()) {
		cout << "������ �������� �����! \n";
		return 0;
	}
	return 1;
}

// ���������� ��������
void Sharpening(cv::Mat* source, cv::Mat* dst, cv::Mat &kernel, cv::Point anchor, double delta) {
	kernel = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(*source, *dst,-1, kernel, anchor, delta, BORDER_DEFAULT);
}

// ��������
void Emboss(cv::Mat* source, cv::Mat* dst, cv::Mat& kernel, cv::Point anchor, double delta) {
	kernel = (Mat_<double>(3, 3) << 1, 0, 0, 0, 0, 0, 0, 0, -1);
	filter2D(*source, *dst, -1, kernel, anchor, delta, BORDER_DEFAULT);
}

// ������ ������
void Sobel(cv::Mat* source, cv::Mat* dst, cv::Mat& kernel, cv::Point anchor, double delta) {
	kernel = (Mat_<double>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
	filter2D(*source, *dst, -1, kernel, anchor, delta, BORDER_DEFAULT);
}


// �������� ��������� �����
bool CheckOutput(String file) {
	ifstream f1(file);
	f1.open(file);
	if (!f1.is_open()) {
		return false;
	}
	else {
		return true;
	}
}

