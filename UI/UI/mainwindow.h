#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QButtonGroup>
#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QTimer>
#include <vector>
#include <QFile>
#include <string>
#include <QDebug>
#include <sstream>
#include <fstream>
#include <QDir>

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QImage last_image;
    QImage bin_image;
    QImage sub_bin_image;
    QImage gray_bin_image;
    QImage svm_num_image;
    QImage svm_bin_image;
    Mat image;
    virtual void timerEvent( QTimerEvent *event);
    string tuneParaFlag;

    string DEBUG_flag;
    string DEBUG_COLOR_flag;
    string GET_NUMBER_flag;
    string GET_FPS_flag;
    string CLC_FPS_flag;

    int RED_COLOR_THRESH_value;
    int RED_GRAY_THRESH_value;
    int BLUE_COLOR_THRESH_value;
    int BLUE_GRAY_THRESH_value;
    int SVM_THRESH_value;

    QButtonGroup *groupButton1;

    QString enemyColor;

    QString path;
    QDir dir;

    string configPath;//config.txt path


private:
    Ui::MainWindow *ui;
    int m_nTimerID;

    int readImageCnt;//读取图片CNT
    string readImagePath;//读取图片定路径
    string readImagePath2;
    string readImagePath_last;
    string readImagePath_bin;
    string readImagePath_sub_bin;
    string readImagePath_gray_bin;
    string readImagePath_svm_num;
    string readImagePath_svm_bin;
    stringstream ss;//用于转换字符串
    int max_readCnt;//最大当前读读取的图片


private slots:
    void showImages();
    void savePara();
    void flushPara();

    void on_tunePara_stateChanged(int arg1);
    void on_DEBUG_stateChanged(int arg1);
    void on_DEBUG_COLOR_stateChanged(int arg1);
    void on_GET_NUMBER_stateChanged(int arg1);
    void on_GET_FPS_stateChanged(int arg1);
    void on_CLC_FPS_stateChanged(int arg1);


    void slots_enemyColor();
    void on_SavePara_clicked();
};

#endif // MAINWINDOW_H
