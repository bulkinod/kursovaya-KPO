#pragma once
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include "header.h"
#include <fstream>
#include <string>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");
	// Declare variables
	Mat src, dst;
	Mat kernel;
	Point anchor;
	double delta;
	int ddepth;
	const char* window_name = "filter";
	String imageName;
	anchor = Point(-1, -1);
	delta = 0;
	ddepth = -1;
	int choice;
	String outfile;


	do {
		cout << "������� ���� �� ����� ��� ��������� - ";
		cin >> imageName;
		if (CheckFormat(imageName, src) == 0) {
			return 0;
		}
		cout << "������� ����� ��������� �������" << endl;
		cout << "0) ����� �� ����" << endl;
		cout << "1) ��������" << endl;
		cout << "2) ���������� ��������" << endl;
		cout << "3) ��������" << endl;
		cout << "4) ������ ������" << endl;
		cin >> choice;

		switch (choice) {
		case 0:
			break;
		case 1:
			cout << "������� ���� �� ����� ���������������� �����������" << endl;
			cin >> outfile;
			if (CheckOutput(outfile) == 0) {
				cout << "���� �� ����� ������ �������";
				return 0;
			}
			Emboss(&src, &dst, kernel, anchor, delta);
			cv::imwrite(outfile, dst);
			cout << "����������� �������� � ��������� ����!" << endl;
			break;

		case 2:
			cout << "������� ���� �� ����� ���������������� �����������" << endl;
			cin >> outfile;
			if (CheckOutput(outfile) == 0) {
				cout << "���� �� ����� ������ �������";
				return 0;
			}
			Sharpening(&src, &dst, kernel, anchor, delta);
			cv::imwrite(outfile, dst);
			cout << "����������� �������� � ��������� ����!" << endl;
			break;

		case 3:
			cout << "������� ���� �� ����� ���������������� �����������" << endl;
			cin >> outfile;
			if (CheckOutput(outfile) == 0) {
				cout << "���� �� ����� ������ �������";
				return 0;
			}
			blur(src, dst, Size(5, 5), anchor);
			cv::imwrite(outfile, dst);
			cout << "����������� �������� � ��������� ����!" << endl;
			break;
		case 4:
			cout << "������� ���� �� ����� ���������������� �����������" << endl;
			cin >> outfile;
			if (CheckOutput(outfile) == 0) {
				cout << "���� �� ����� ������ �������";
				return 0;
			}
			Sobel(&src, &dst, kernel, anchor, delta);
			cv::imwrite(outfile, dst);
			cout << "����������� �������� � ��������� ����!" << endl;
			break;
		default:
			cout << "������������ ����!" << endl;
			return 0;
		}


	} while (choice != 0);

	
		
	
	
	
	
	
		
	return 0;
	
}
	