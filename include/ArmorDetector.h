#ifndef _DETECTOR_H_
#define _DETECTOR_H_
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "Config.h"
#include <queue>
#include <sys/stat.h>
#include <sys/types.h>

#define PI 3.14159265
#define BIG 0
#define SMALL 1

using namespace std;
using namespace cv;

typedef struct ANGLE
{
	float yaw;
	float pitch;
} Angle;

class Armor
{
private:
	vector<Point2f> rect;

public:
	int number;
	Point2f center;
	float d_x, d_z, d_y;

private:
	void getPnp();

public:
	Armor();
	Armor(vector<Point2f> rect_target, Rect roi_rect, int num);
	Armor(const Armor &other);
};

class Detector
{
private:
	Mat binary;	 //binary image
	Mat outline; //outline image
	int num;
	Rect Armor_roi;
	vector<vector<Point>> contours;
	float matchrank[1500][1500];
	Ptr<ml::SVM> svm = ml::SVM::load("cxy_svm_5_1.xml");
	Config configSettings;

	int color_thresh = 20; //通道相减二值化阈值
	int gray_thresh = 20;  //灰度图二值化阈值
	int SVM_thresh = -1;

public:
	Mat src; //source image
	Mat src_out;
	bool islost; //1代表丢失
	Mat number_roi;

	vector<Armor> detect_armor;
	Armor target_armor;

	//UI
	int saveImageCnt;  //保存图片全局cnt
	int saveImagePath; //保存图片的路径
	stringstream ss;
	string saveString1, saveString2, saveStringCnt; //保存图片使用变量

	string readPara; //判断时否重新读取配置文件

	int DEBUG;
	int GET_NUMBER;
	int GET_FPS_FLAG;
	int CLC_FPS_FLAG;

	Mat image_tmp;

	int enemyColor;

private:
	Mat pointProcess(Mat srcImg, int enemyColor, int color_threshold, int gry_threshold);
	void imgProcess(Mat &tempBinary);
	/////////////////////////////装甲板//////////////////////////////////
	int getNumber(vector<Point2f> rect_t);
	int isArmorPattern(Mat &front);
	void getRoi(Point2f center, Point2f size);

	/////////////////////////////GUI////////////////////////////////////
	void getConfig();
	void generateSavePath(); //生成保存图片定路径
	void saveImage();

public:
	Detector();
	Detector(Mat src0);
	void getResult();
	void getSrcImage(Mat src0);
	void getBinaryImage();
	void getContours();
	void getTarget();
};
#endif
