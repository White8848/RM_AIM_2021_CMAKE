#define _CRT_SECURE_NO_WARNINGS
#include "ArmorDetector.h"

/////////////////////////////////////INIT////////////////////////////////////////////
Detector::Detector()
{
	islost = true;

	const char ConfigFile[] = "config.txt";
	configSettings.ReadFile(ConfigFile); //读取配置文件

	generateSavePath();
}

Detector::Detector(Mat src0)
{
	src0.copyTo(src);
	islost = true;
}

/////////////////////////////////////PUBLIC//////////////////////////////////////////
void Detector::getResult()
{
#ifdef UI
	getConfig();
#endif

	getBinaryImage();
	getContours();
	getTarget();

#ifdef UI
	saveImage();
#endif
}

//获取图像
void Detector::getSrcImage(Mat src0)
{
	src0.copyTo(src_out);
	if (islost == true)
	{
		Armor_roi = Rect(0, 0, src0.cols, src0.rows);
	}

#ifdef UI
	Armor_roi = Rect(0, 0, src0.cols, src0.rows);
#endif

	src = src0(Armor_roi);
}

//二值化
void Detector::getBinaryImage()
{
	Mat gry;
	src.copyTo(gry);
	//imshow("gry", gry);
	if (enemyColor == 1)
	{
		color_thresh = configSettings.Read("RED_COLOR_THRESH", color_thresh);
		gray_thresh = configSettings.Read("RED_GRAY_THRESH", gray_thresh);
	}
	else
	{
		color_thresh = configSettings.Read("BLUE_COLOR_THRESH", color_thresh);
		gray_thresh = configSettings.Read("BLUE_GRAY_THRESH", gray_thresh);
	}
	binary = pointProcess(gry, enemyColor, color_thresh, gray_thresh); //二值化
}

//扫描装甲板
void Detector::getContours()
{
	vector<Vec4i> hierarcy;
	Point2f rect[4];
	findContours(binary, contours, hierarcy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE); //CV_CHAIN_APPROX_NONE

	vector<vector<Point>>::iterator itc = contours.begin();
	while (itc != contours.end())
	{
		if (itc->size() < 35)
		{
			itc = contours.erase(itc);
		}
		else
		{
			itc++;
		}
	}
	vector<Rect> boundRect(contours.size());
	vector<RotatedRect> box(contours.size()); //最小外接矩形集合
	num = contours.size();					  //轮廓的数量

#ifdef UI
	if (DEBUG == 1)
		src.copyTo(outline);
#endif

	for (int i = 0; i < num; i++)
	{
		box[i] = minAreaRect(Mat(contours[i])); //计算每个轮廓的最小外接矩形
#ifdef UI

		if (DEBUG == 1)
		{
			boundRect[i] = boundingRect(Mat(contours[i]));
			circle(outline, Point(box[i].center.x, box[i].center.y), 5, Scalar(0, 255, 0), -1, 8);
			box[i].points(rect);
			rectangle(outline, Point(boundRect[i].x, boundRect[i].y), Point(boundRect[i].x + boundRect[i].width, boundRect[i].y + boundRect[i].height), Scalar(0, 255, 0), 2, 8);
			for (int j = 0; j < 4; j++)
			{
				line(outline, rect[j], rect[(j + 1) % 4], Scalar(0, 0, 255), 2, 8); //绘制最小外接矩形每条边（非必要）
			}
		}

#endif
	}

	memset(matchrank, 0, sizeof(matchrank));
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			//去掉太斜的矩形
			if ((box[i].size.width > box[i].size.height && box[i].angle > -77) || (box[i].size.width < box[i].size.height && box[i].angle < -13))
				matchrank[i][j] -= 100000;
			if ((box[j].size.width > box[j].size.height && box[j].angle > -77) || (box[j].size.width < box[j].size.height && box[j].angle < -13))
				matchrank[i][j] -= 100000;
			//根据长宽筛选
			double longi, shorti, longj, shortj;
			longi = box[i].size.height;
			shorti = box[i].size.width;
			if (longi < shorti)
			{
				int temp = longi;
				longi = shorti;
				shorti = temp;
			}
			longj = box[j].size.height;
			shortj = box[j].size.width;
			if (longj < shortj)
			{
				int temp = longj;
				longj = shortj;
				shortj = temp;
			}

			if ((longi / shorti) >= 0.7 && (longi / shorti) <= 1.8 && (longj / shortj) >= 0.7 && (longj / shortj) <= 1.8)
				matchrank[i][j] -= 10000;
			if ((longi / shorti) >= 1.8 && (longi / shorti) <= 2.8 && (longj / shortj) >= 1.8 && (longj / shortj) <= 2.8) //两个轮廓的长宽比
				matchrank[i][j] += 100;
			//相对位置筛选
			if ((box[i].center.y - box[j].center.y) > 0.5 * longi || (box[i].center.y - box[j].center.y) > 0.5 * longj)
				matchrank[i][j] -= 10000;
			if (abs(box[i].center.x - box[j].center.x) < 0.8 * longi || abs(box[i].center.x - box[j].center.x) < 0.8 * longj)
				matchrank[i][j] -= 10000;
			//根据角度筛选
			double anglei, anglej;
			anglei = box[i].angle;
			anglej = box[j].angle;
			if (abs(anglei - anglej) <= 10 || abs(anglei - anglej) >= 80)
				matchrank[i][j] += 100;
			else
				matchrank[i][j] -= 10000;
			//面积比
			double areai = box[i].size.area();
			double areaj = box[j].size.area();
			if (areai < 7 || areaj < 7)
				matchrank[i][j] -= 20000;
			if (areai / areaj >= 5 || areaj / areai >= 5)
				matchrank[i][j] -= 10000;
			if (areai / areaj >= 2 || areaj / areai >= 2)
				matchrank[i][j] -= 100;
			if (areai / areaj > 0.8 && areai - areaj < 1.2)
				matchrank[i][j] += 100;
			//连线长
			double d = sqrt((box[i].center.x - box[j].center.x) * (box[i].center.x - box[j].center.x) + (box[i].center.y - box[j].center.y) * (box[i].center.y - box[j].center.y));
			if (d >= longi * 4.5 || d >= longj * 4.5 || d < 2 * longi || d < 2 * longj)
				matchrank[i][j] -= 10000;
			//cout<<"i j d:"<<i<<" "<<j<<" "<<d<<endl;
		}
	}
}

//获取目标
void Detector::getTarget()
{
	int amount = 0;
	int rect_index[][2] = {-1};
	int temp[2] = {-1};
	int armor_mark[] = {0};
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (matchrank[i][j] > 0)
			{
				armor_mark[amount] = matchrank[i][j];
				rect_index[amount][0] = i;
				rect_index[amount][1] = j;
				amount++;
			}
		}
	}
	if (rect_index[0][0] == -1 || rect_index[0][1] == -1)
	{
		islost = true;
		return;
	}
	islost = false;
	RotatedRect boxi;
	RotatedRect boxj;
	int armor_num = 0;
	for (int i = 0; i < amount; i++)
	{
		//获取最优匹配
		boxi = minAreaRect(Mat(contours[rect_index[i][0]]));
		boxj = minAreaRect(Mat(contours[rect_index[i][1]]));

		//获取周围四个点的坐标
		if (boxi.center.x > boxj.center.x)
		{
			RotatedRect temp;
			temp = boxi;
			boxi = boxj;
			boxj = temp;
		}
		Point2f rect_left[4];
		Point2f rect_right[4];
		boxi.points(rect_left);
		boxj.points(rect_right);

		vector<Point2f> rect_target(4);

		double d1 = sqrt((rect_left[0].x - rect_left[1].x) * (rect_left[0].x - rect_left[1].x) + (rect_left[0].y - rect_left[1].y) * (rect_left[0].y - rect_left[1].y));
		double d2 = sqrt((rect_left[1].x - rect_left[2].x) * (rect_left[1].x - rect_left[2].x) + (rect_left[1].y - rect_left[2].y) * (rect_left[1].y - rect_left[2].y));
		double d3 = sqrt((rect_right[0].x - rect_right[1].x) * (rect_right[0].x - rect_right[1].x) + (rect_right[0].y - rect_right[1].y) * (rect_right[0].y - rect_right[1].y));
		double d4 = sqrt((rect_right[1].x - rect_right[2].x) * (rect_right[1].x - rect_right[2].x) + (rect_right[1].y - rect_right[2].y) * (rect_right[1].y - rect_right[2].y));
		if (d1 > d2)
		{
			rect_target[0] = (rect_left[0] + rect_left[3]) / 2; //左下
			rect_target[1] = (rect_left[1] + rect_left[2]) / 2; //左上
		}
		else
		{
			rect_target[0] = (rect_left[0] + rect_left[1]) / 2; //左下
			rect_target[1] = (rect_left[2] + rect_left[3]) / 2; //左上
		}
		if (d3 > d4)
		{
			rect_target[2] = (rect_right[1] + rect_right[2]) / 2; //右上
			rect_target[3] = (rect_right[0] + rect_right[3]) / 2; //右下
		}
		else
		{
			rect_target[2] = (rect_right[2] + rect_right[3]) / 2; //右上
			rect_target[3] = (rect_right[0] + rect_right[1]) / 2; //右下
		}

#ifdef UI
		for (int j = 0; j < 4; j++)//绘制装甲板的边缘
		{
			line(src_out, rect_target[j], rect_target[(j + 1) % 4], Scalar(0, 0, 255), 2, 8); 
			line(src_out, rect_left[j], rect_left[(j + 1) % 4], Scalar(0, 0, 255), 2, 8);
			line(src_out, rect_right[j], rect_right[(j + 1) % 4], Scalar(0, 0, 255), 2, 8);
		}
		// line(src_out, rect_left[0], rect_left[1], Scalar(0, 0, 255), 2, 8); //绘制最小外接矩形每条边（非必要）
		// line(src_out, rect_left[1], rect_left[2], Scalar(0, 255, 0), 2, 8); //绘制最小外接矩形每条边（非必要）
#endif

		int number = 0;
		double e1, e2;
		e1 = getTickCount();
		number = getNumber(rect_target);
		e2 = getTickCount();
		float time = (e2 - e1) / getTickFrequency();
		//cout<<"svm_time="<<time*1000<<"ms"<<endl;
		//cout<<"armor_number"<<number<<endl;
		//number = 1;
		if (number != 0)
		{
			detect_armor.push_back(Armor(rect_target, Armor_roi, number));

#ifdef UI
			circle(src_out, Point2f(detect_armor[armor_num].center.x, detect_armor[armor_num].center.y), 5, Scalar(255, 0, 0), -1, 8);
			char tam[100];
			sprintf(tam, "(%0.0f,%0.0f)", detect_armor[armor_num].center.x, detect_armor[armor_num].center.y);
			putText(src_out, tam, Point2f(detect_armor[armor_num].center.x, detect_armor[armor_num].center.y), FONT_HERSHEY_SIMPLEX, 0.4, Scalar(255, 0, 255), 1);
#endif

			armor_num++;
		}
	}
	if (detect_armor.size() != 0)
	{
		target_armor = detect_armor[0];
		Point2f size(100, 100);
		getRoi(target_armor.center, size);
		detect_armor.clear();
	}
	else
	{
		islost = true;
	}
}

/////////////////////////////////////PRIVATE//////////////////////////////////////////
//判断数字
int Detector::getNumber(vector<Point2f> rect_t)
{
	//数字识别roi
	vector<Point> contour;
	contour.push_back(rect_t[0]);
	contour.push_back(rect_t[1]);
	contour.push_back(rect_t[2]);
	contour.push_back(rect_t[3]);
	RotatedRect rect = minAreaRect(contour);
	Point2f center((rect_t[0].x + rect_t[1].x + rect_t[2].x + rect_t[3].x) / 4, (rect_t[0].y + rect_t[1].y + rect_t[2].y + rect_t[3].y) / 4);
	//cout<<"angle:"<<rect.angle<<endl;
	Mat M;
	double p1, p2;

	if (rect.angle < -40)
	{
		rect.angle += 90;
		swap(rect.size.width, rect.size.height);
	}
	//cout << "angle=" << rect.angle << endl;
	//1280 1024 src.cols src.rows
	p1 = center.x - (rect.size.width / 2);
	p2 = center.y - (rect.size.height / 2);
	M = getRotationMatrix2D(center, rect.angle, 1.0); //求旋转矩阵

	Mat rot_image;
	warpAffine(src, rot_image, M, src.size(), 0, 0, 0); //原图像旋转

	float x = center.x - (rect.size.width / 2), y = center.y - (rect.size.height / 2) - 20;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	float w = (center.x - x) * 2, h = (center.y - y) * 2;
	if (x + w > rot_image.cols)
		w = rot_image.cols - x;
	if (y + h > rot_image.rows)
		h = rot_image.rows - y;

	//cout << "x=" << x << " y=" << y << " h=" << h << " w=" << w << endl;
	number_roi = rot_image(Rect(x, y, w, h)); //提取ROI
	// for (int j = 0; j < 4; j++)
	// {
	// 	line(rot_image, rect_t[j], rect_t[(j + 1) % 4], Scalar(0, 0, 255), 2, 8); //绘制最小外接矩形每条边（非必要）
	// }
	//imshow("rot_image", rot_image);

	if (!number_roi.empty())
	{
		//imshow("number", number_roi);
#ifdef UI
	resize(number_roi, image_tmp, Size(160, 160));
	saveString2 = saveString1 + "svm/" + saveStringCnt + ".PNG";
	imwrite(saveString2, image_tmp);
#endif
		return isArmorPattern(number_roi);

	}

	return 0;
}

int Detector::isArmorPattern(Mat &front)
{
	Mat gray;
	cv::cvtColor(front, gray, CV_BGR2GRAY);
	cv::resize(gray, gray, Size(20, 20));
	GaussianBlur(gray, gray, Size(3, 3), 0, 0);
	adaptiveThreshold(gray, gray, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, SVM_thresh);
	//threshold(gray, gray, 80, 255, CV_THRESH_BINARY);
	//imshow("xxx", gray);
	// copy the data to make the matrix continuous

#ifdef UI
	resize(gray, image_tmp, Size(160, 160));
	saveString2 = saveString1 + "svm_bin/" + saveStringCnt + ".PNG";
	imwrite(saveString2, image_tmp);
#endif 
	Mat temp;
	gray.copyTo(temp);
	Mat data = temp.reshape(1, 1);

	data.convertTo(data, CV_32FC1);

	//Ptr<ml::SVM> svm = ml::SVM::load("cxy_svm_5_1.xml");

	int result = (int)svm->predict(data);

	return result;
}

void Detector::getRoi(Point2f center, Point2f size)
{
	int x = 0, y = 0, w = 0, h = 0;

	x = center.x - size.x;
	y = center.y - size.y;
	w = (center.x - x) * 2;
	h = (center.y - y) * 2;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x + w > src_out.cols)
		w = src_out.cols - x;
	if (y + h > src_out.rows)
		h = src_out.rows - y;

	Armor_roi = Rect(x, y, w, h);
}

//处理图像
Mat Detector::pointProcess(Mat srcImg, int enemyColor, int color_threshold, int gry_threshold)
{
	Mat tempBinary;
	Mat gryBinary;

	tempBinary = Mat::zeros(srcImg.size(), CV_8UC1);
	cv::cvtColor(srcImg, gryBinary, CV_BGR2GRAY);

	vector<Mat> g_imgChannels;
	Mat g_imgChannels0;
	Mat g_tempBinary;

	split(src, g_imgChannels);

	if (enemyColor == 1) //RED
	{
		//tempBinary=imgChannels.at(2)-imgChannels.at(0)-imgChannels.at(1);
		subtract(g_imgChannels.at(2), g_imgChannels.at(0), g_imgChannels0);
		subtract(g_imgChannels0, g_imgChannels[1], g_tempBinary);
	}
	else //BLUE
	{
		//tempBinary=imgChannels.at(0)-imgChannels.at(2);
		subtract(g_imgChannels.at(0), g_imgChannels.at(2), g_tempBinary);
	}
	threshold(g_tempBinary, tempBinary, color_threshold, 255, CV_THRESH_BINARY);

	imgProcess(tempBinary);
	GaussianBlur(gryBinary, gryBinary, Size(3, 3), 0, 0);
	// adaptiveThreshold(gryBinary, gryBinary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, gry_threshold); //自适应阈值化
	threshold(gryBinary, gryBinary, gry_threshold, 255, THRESH_BINARY);

#ifdef UI
	resize(tempBinary, image_tmp, Size(640, 480));
	saveString2 = saveString1 + "sub_bin/" + saveStringCnt + ".PNG";
	imwrite(saveString2, image_tmp);

	resize(gryBinary, image_tmp, Size(640, 480));
	saveString2 = saveString1 + "gray_bin/" + saveStringCnt + ".PNG";
	imwrite(saveString2, image_tmp);

	saveImageCnt++;

	// waitKey(20);

	string tmp;
	ss << saveImageCnt;
	ss >> tmp;
	ss.clear();

	ofstream outfile("UI_DEBUG/UI_file/max_readCnt.txt", ios::trunc);

	outfile << tmp;

	if (saveImageCnt == 3)
		saveImageCnt = 0;
#endif

	return tempBinary & gryBinary;
}

//膨胀腐蚀操作
void Detector::imgProcess(Mat &tempBinary)
{
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	erode(tempBinary, tempBinary, kernel);
	dilate(tempBinary, tempBinary, kernel);
	//dilate(tempBinary, tempBinary, kernel);
	//erode(tempBinary, tempBinary, kernel);
}

void Detector::getConfig()
{
	ifstream myfile("UI_DEBUG/UI_file/readPara.txt");

	myfile >> readPara;
	myfile.close();

	if (readPara == "1")
	{
		const char ConfigFile[] = "UI_DEBUG/UI_file/DebugConfig.txt";
		configSettings.ReadFile(ConfigFile); //读取配置文件
	}

	DEBUG = configSettings.Read("DEBUG", DEBUG);
	GET_NUMBER = configSettings.Read("GET_NUMBER", GET_NUMBER);
	GET_FPS_FLAG = configSettings.Read("GET_FPS", GET_FPS_FLAG);
	CLC_FPS_FLAG = configSettings.Read("CLC_FPS", CLC_FPS_FLAG);

	enemyColor = configSettings.Read("enemyColor", enemyColor);

	SVM_thresh = configSettings.Read("SVM_thresh", SVM_thresh);

	if (SVM_thresh >= 256) SVM_thresh = -(SVM_thresh-255);
}
void Detector::saveImage()
{
	Mat last;

	saveStringCnt = "";
	saveString1 = "";
	saveString2 = "";
	ss << saveImageCnt;
	ss >> saveStringCnt;
	ss.clear();

	saveString2 = "image";

	saveString1 = "UI_DEBUG/UI_file/image/" + saveString2 + "/";
	saveString2 = saveString1 + "last/" + saveStringCnt + ".PNG";

	cvtColor(src_out, last, COLOR_BGR2RGB);

	resize(last, image_tmp, Size(640, 480));
	imwrite(saveString2, image_tmp);

	resize(binary, image_tmp, Size(640, 480));
	saveString2 = saveString1 + "bin/" + saveStringCnt + ".PNG";
	imwrite(saveString2, image_tmp);

	if (waitKey(1) == 27)
		exit(0);
}

void Detector::generateSavePath()
{

	string tmp = "image";

	string test;
	test = "UI_DEBUG/UI_file/image/" + tmp;
	mkdir(test.c_str(), S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);

	test = "UI_DEBUG/UI_file/image/" + tmp + "/last";
	mkdir(test.c_str(), S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);

	test = "UI_DEBUG/UI_file/image/" + tmp + "/bin";
	mkdir(test.c_str(), S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);

	test = "UI/UI_DEBUG/UI_file/image/" + tmp + "/sub_bin";
	mkdir(test.c_str(), S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);

	test = "UI_DEBUG/UI_file/image/" + tmp + "/gray_bin";
	mkdir(test.c_str(), S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);

	test = "UI_DEBUG/UI_file/image/" + tmp + "/svm_bin";
	mkdir(test.c_str(), S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);

	test = "UI_DEBUG/UI_file/image/" + tmp + "/svm";
	mkdir(test.c_str(), S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);
}