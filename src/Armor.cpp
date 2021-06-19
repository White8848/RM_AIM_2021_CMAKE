#define _CRT_SECURE_NO_WARNINGS
#include "ArmorDetector.h"

Armor::Armor()
{
    center = Point2f(0, 0);
}
//装甲板初始化
Armor::Armor(vector<Point2f> rect_target, Rect roi_rect, int num)
{
    number = num;
    center.x = roi_rect.x + (rect_target[0].x + rect_target[1].x + rect_target[2].x + rect_target[3].x) / 4;
    center.y = roi_rect.y + (rect_target[0].y + rect_target[1].y + rect_target[2].y + rect_target[3].y) / 4;
    rect.assign(rect_target.begin(),rect_target.end());
}

Armor::Armor(const Armor& other)
{
    number = other.number;
    center = other.center;
    rect.assign(other.rect.begin(),other.rect.end());
}
//pnp坐标解算
void Armor::getPnp()
{
    double camera1[9] = {1000, 0, 320, 0, 1000, 240, 0, 0, 1};
    double theerror1[5] = {0, 0, 0.0, 0.00, 0.0};
    double camera2[9] = {2105.39, 0, 640, 0, 2105.39, 512, 0, 0, 1}; //相机内参
    double theerror2[5] = {-0.110008, 2.220571, 0.0, 0.0, -14.069738};
    //Rect ans = trackBox;

    //判断大小装甲板
    float height = sqrt(pow((rect[1].x - rect[0].x), 2) + pow((rect[1].y - rect[0].y), 2));
    float width = sqrt(pow((rect[1].x - rect[2].x), 2) + pow((rect[1].y - rect[2].y), 2));
    float p = width / height;
    bool size;
    if (p <= 4.5 && p >= 2.8)
    {
        size = BIG;
        //cout << "BIG_ARMOR" << endl;
    }
    else if (p < 2.8 && p >= 1.3)
    {
        size = SMALL;
        //cout << "SMALL_ARMOR" << endl;
    }

    double width_target, height_target;
    if (size == BIG)
        width_target = 22.5;
    else
        width_target = 13;
    height_target = 6;

    vector<Point2d> point2d;
    point2d.push_back(rect[0]);
    point2d.push_back(rect[2]);
    point2d.push_back(rect[3]);
    point2d.push_back(rect[1]);
    point2d.push_back(center);

    std::vector<cv::Point3d> point3d;
    double half_x = width_target / 2.0;
    double half_y = height_target / 2.0;
    point3d.push_back(Point3d(-half_x, -half_y, 0));
    point3d.push_back(Point3d(half_x, -half_y, 0));
    point3d.push_back(Point3d(half_x, half_y, 0));
    point3d.push_back(Point3d(-half_x, half_y, 0));
    point3d.push_back(Point3d(0, 0, 0));
    Mat cam(Size(3, 3), CV_64F, camera2);
    Mat dist(Size(5, 1), CV_64F, theerror2);
    Mat rvec(3, 3, CV_64F);
    Mat trec(3, 1, CV_64F);

    solvePnP(point3d, point2d, cam, dist, rvec, trec, false, CV_EPNP);
    double ans_x, ans_y, ans_z;
    //cout<<trec<<endl;
    ans_x = trec.at<double>(0, 0);
    ans_y = trec.at<double>(1, 0);
    ans_z = trec.at<double>(2, 0);
    double dis_x = 0, dis_y = 0;

    d_y = (acos(35.0 / sqrt((ans_x + 35.0) * (ans_x + 35.0) + (ans_z + 127) * (ans_z + 127))) - acos((ans_x + 35.0) / sqrt((ans_x + 35.0) * (ans_x + 35.0) + (ans_z + 127) * (ans_z + 127)))) * 180 / 3.1415926;
    d_z = ans_z;
    //cout<<ans_x<<" "<<ans_y<<endl<<endl;;
    d_x = atan((ans_y) / (ans_z)) * 180 / 3.1415926;
    //d_y=atan(ans_x/ans_z)*180/3.1415926;
    //d_z=ans_z;
    //cout << d_x << " " << d_y << " " << d_z << endl << endl;;
    //cout<<"  ans "<<x<<"   "<<last_x<<endl;

    //cout<<"Distance = "<<target.d_z - 10<<endl;
}