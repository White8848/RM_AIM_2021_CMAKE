#include "mainwindow.h"
#include "ui_mainwindow.h"
#define TIMER_TIMEOUT  1


string getNum(int str){\
    stringstream ss;
    string tmp;
    ss << str;
    ss >> tmp;
    ss.clear();
    return tmp;
}

QString getNum(QString str){

    QString tmp;
    for(int j = 0; j < str.length(); j++)
    {
      if(str[j] >= '0' && str[j] <= '9')
        tmp.append(str[j]);
    }

    return tmp;
}

string getNum(string str){

    QString tmp;
    for(int j = 0; j < str.length(); j++)
    {
      if(str[j] >= '0' && str[j] <= '9')
        tmp.append(str[j]);
    }

    return tmp.toStdString();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    path = QCoreApplication::applicationDirPath();

    //初始化参数 否则会报错
    image = imread(path.toStdString() + "/UI_file/initImage.PNG",COLOR_BGR2RGB);
    last_image = QImage((const unsigned char*)image.data, image.cols, image.rows, image.cols * image.channels(), QImage::Format_RGB888);
    bin_image = QImage((const unsigned char*)image.data, image.cols, image.rows, image.cols * image.channels(), QImage::Format_RGB888);
    sub_bin_image = QImage((const unsigned char*)image.data, image.cols, image.rows, image.cols * image.channels(), QImage::Format_RGB888);
    gray_bin_image = QImage((const unsigned char*)image.data, image.cols, image.rows, image.cols * image.channels(), QImage::Format_RGB888);

    groupButton1=new QButtonGroup(this);
    groupButton1->addButton(ui->RED,0);
    groupButton1->addButton(ui->BLUE,1);

    connect(ui->RED,SIGNAL(clicked(bool)),
                this,SLOT(slots_enemyColor()));
    connect(ui->BLUE,SIGNAL(clicked(bool)),
                this,SLOT(slots_enemyColor()));

    readImageCnt = 0;
    max_readCnt = 0;

     DEBUG_flag = "0";
     DEBUG_COLOR_flag = "0";
     GET_NUMBER_flag = "0";
     GET_FPS_flag = "0";
     CLC_FPS_flag = "0";


     QString tmp("0");

//     RED_COLOR_THRESH_value = tmp;
//     RED_GRAY_THRESH_value = tmp;
//     BLUE_COLOR_THRESH_value = tmp;
//     BLUE_GRAY_THRESH_value = tmp;

//     ui->BLUE_COLOR_THRESH->setText(tmp);
     ui->BLUE_COLOR_THRESH->setValue(tmp.toInt());
     ui->BLUE_GRAY_THRESH->setValue(tmp.toInt());
     ui->RED_COLOR_THRESH->setValue(tmp.toInt());
     ui->RED_GRAY_THRESH->setValue(tmp.toInt());

     enemyColor = "1";//RED
     ui->RED->setChecked(1);

     tuneParaFlag = "0";
     //读取文件初始化参数

     QFile readImageFile(path + "/UI_file/initPara.txt");
     QString QSread[11];

    //初始化
    int j = 0;
    for (j = 0; j <= 10; ++j){

        QSread[j] = tmp;
    }

    int i = 0;
    if(!readImageFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }
    while(!readImageFile.atEnd()){

        QByteArray line = readImageFile.readLine();

        QString str(line);

        QSread[i++] = str;

//        qDebug() << QSread[i-1];
    }

    DEBUG_flag = QSread[0].toStdString();
    DEBUG_COLOR_flag = QSread[1].toStdString();
    GET_NUMBER_flag = QSread[2].toStdString();
    GET_FPS_flag = QSread[3].toStdString();
    CLC_FPS_flag = QSread[4].toStdString();

    string tmp2 = getNum(QSread[0]).toStdString();
    if (tmp2 == "1") {
        ui->DEBUG->setCheckState(Qt::Checked);
    }

    tmp2 = getNum(QSread[1]).toStdString();
    if (tmp2 == "1") ui->DEBUG_COLOR->setCheckState(Qt::Checked);

    tmp2 = getNum(QSread[2]).toStdString();
    if (tmp2 == "1") ui->GET_NUMBER->setCheckState(Qt::Checked);

    tmp2 = getNum(QSread[3]).toStdString();
    if (tmp2 == "1") ui->GET_FPS->setCheckState(Qt::Checked);

    tmp2 = getNum(QSread[4]).toStdString();
    if (tmp2 == "1") ui->CLC_FPS->setCheckState(Qt::Checked);


    ui->BLUE_COLOR_THRESH->setValue(QSread[5].toInt());
    ui->BLUE_GRAY_THRESH->setValue(QSread[6].toInt());
    ui->RED_COLOR_THRESH->setValue(QSread[7].toInt());
    ui->RED_GRAY_THRESH->setValue(QSread[8].toInt());

    ui->BLUE_COLOR->setValue(QSread[5].toInt());
    ui->BLUE_GRAY->setValue(QSread[6].toInt());
    ui->RED_COLOR->setValue(QSread[7].toInt());
    ui->RED_GRAY->setValue(QSread[8].toInt());

    int tmp_int = QSread[10].toInt();
    if (tmp_int >= 256) tmp_int = 255-tmp_int;

    ui->SVM_THRESH->setValue(QSread[10].toInt());
    ui->SVM->setValue(QSread[10].toInt());

    string tmp1 = getNum(QSread[9]).toStdString();
    if (tmp1 == "1"){
        enemyColor = "1";//RED
        ui->RED->setChecked(1);
    }
    else{
        enemyColor = "0";//blue
        ui->BLUE->setChecked(1);
    }

    readImagePath = "image";

    //链接信号
    connect(ui->BLUE_COLOR, SIGNAL(valueChanged(int)), ui->BLUE_COLOR_THRESH, SLOT(setValue(int)));
    connect(ui->BLUE_COLOR_THRESH, SIGNAL(valueChanged(int)), ui->BLUE_COLOR, SLOT(setValue(int)));

    connect(ui->BLUE_GRAY, SIGNAL(valueChanged(int)), ui->BLUE_GRAY_THRESH, SLOT(setValue(int)));
    connect(ui->BLUE_GRAY_THRESH, SIGNAL(valueChanged(int)), ui->BLUE_GRAY, SLOT(setValue(int)));

    connect(ui->RED_COLOR, SIGNAL(valueChanged(int)), ui->RED_COLOR_THRESH, SLOT(setValue(int)));
    connect(ui->RED_COLOR_THRESH, SIGNAL(valueChanged(int)), ui->RED_COLOR, SLOT(setValue(int)));

    connect(ui->RED_GRAY, SIGNAL(valueChanged(int)), ui->RED_GRAY_THRESH, SLOT(setValue(int)));
    connect(ui->RED_GRAY_THRESH, SIGNAL(valueChanged(int)), ui->RED_GRAY, SLOT(setValue(int)));

    connect(ui->SVM, SIGNAL(valueChanged(int)), ui->SVM_THRESH, SLOT(setValue(int)));
    connect(ui->SVM_THRESH, SIGNAL(valueChanged(int)), ui->SVM, SLOT(setValue(int)));

    m_nTimerID = this->startTimer(TIMER_TIMEOUT);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showImages(){

    //读取last
    readImagePath2 = "";
    readImagePath2 = path.toStdString() + "/UI_file/image/" + readImagePath + "/";
    ss << readImageCnt;
    ss >> readImagePath_last;
    ss.clear();
    readImagePath_last = readImagePath2 + "last/" + readImagePath_last + ".PNG";

    image = imread(readImagePath_last,COLOR_BGR2RGB);
    last_image = QImage((const unsigned char*)image.data, image.cols, image.rows, image.cols * image.channels(), QImage::Format_RGB888);
    ui->last->setPixmap(QPixmap::fromImage(last_image));

    //读取bins
    ss << readImageCnt;
    ss >> readImagePath_bin;
    ss.clear();
    readImagePath_bin = readImagePath2 + "bin/" + readImagePath_bin + ".PNG";

    image = imread(readImagePath_bin);
    bin_image = QImage((const unsigned char*)image.data, image.cols, image.rows, image.cols* image.channels(), QImage::Format_RGB888);
    ui->bin->setPixmap(QPixmap::fromImage(bin_image));

    //gray_bin
    ss << readImageCnt;
    ss >> readImagePath_gray_bin;
    ss.clear();
    readImagePath_gray_bin = readImagePath2 + "gray_bin/" + readImagePath_gray_bin + ".PNG";

    image = imread(readImagePath_gray_bin);
    gray_bin_image = QImage((const unsigned char*)image.data, image.cols, image.rows, image.cols* image.channels(), QImage::Format_RGB888);
    ui->gray_bin->setPixmap(QPixmap::fromImage(gray_bin_image));

    //sub_bin
    ss << readImageCnt;
    ss >> readImagePath_sub_bin;
    ss.clear();
    readImagePath_sub_bin = readImagePath2 + "sub_bin/" + readImagePath_sub_bin + ".PNG";

    image = imread(readImagePath_sub_bin);
    sub_bin_image = QImage((const unsigned char*)image.data, image.cols, image.rows, image.cols* image.channels(), QImage::Format_RGB888);
    ui->sub_bin->setPixmap(QPixmap::fromImage(sub_bin_image));

    //SVM_NUM
    ss << readImageCnt;
    ss >> readImagePath_svm_num;
    ss.clear();
    readImagePath_svm_num = readImagePath2 + "svm/" + readImagePath_svm_num + ".PNG";

    image = imread(readImagePath_svm_num);
    svm_num_image = QImage((const unsigned char*)image.data, image.cols, image.rows, image.cols* image.channels(), QImage::Format_RGB888);
    ui->SVM_NUM->setPixmap(QPixmap::fromImage(svm_num_image));

    //SVM_BIN
    ss << readImageCnt;
    ss >> readImagePath_svm_bin;
    ss.clear();
    readImagePath_svm_bin = readImagePath2 + "svm_bin/" + readImagePath_svm_bin + ".PNG";

    image = imread(readImagePath_svm_bin);
    svm_bin_image = QImage((const unsigned char*)image.data, image.cols, image.rows, image.cols* image.channels(), QImage::Format_RGB888);
    ui->SVM_BIN->setPixmap(QPixmap::fromImage(svm_bin_image));


    QString str1 = QString::number(readImageCnt);
//    ui->currentReadImageString->setText(str1);

    QFile readImageFile(path + "/UI_file/max_readCnt.txt");
    if(!readImageFile.open(QIODevice::ReadOnly | QIODevice::Text))

    {

        qDebug()<<"Can't open the file!"<<endl;

    }

    QByteArray line = readImageFile.readLine();

    QString str(line);

    max_readCnt =  str.toInt();

//    readImageCnt = max_readCnt==2?0:max_readCnt-1;
    if (max_readCnt == 0){
        readImageCnt = 2;
    }
    else{
        readImageCnt = max_readCnt - 1;
    }

//    qDebug() << max_readCnt << " " << readImageCnt << endl;
}

void MainWindow::savePara(){

}

void MainWindow::flushPara(){

}



void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_nTimerID){

            showImages();

            //写入是否读取参数flag
            ofstream outfile(path.toStdString() + "/UI_file/readPara.txt", ios::trunc);

            outfile << tuneParaFlag;

            if (tuneParaFlag == "1"){
                //写入参数

                ofstream outfile2(path.toStdString() + "/UI_file/DebugConfig.txt", ios::trunc);

                 RED_COLOR_THRESH_value = ui->RED_COLOR_THRESH->value();
                 RED_GRAY_THRESH_value = ui->RED_GRAY_THRESH->value();
                 BLUE_COLOR_THRESH_value = ui->BLUE_COLOR_THRESH->value();
                 BLUE_GRAY_THRESH_value = ui->BLUE_GRAY_THRESH->value();
                 SVM_THRESH_value =ui->SVM_THRESH->value();
                 if (SVM_THRESH_value < 0) SVM_THRESH_value = -SVM_THRESH_value + 255;

                outfile2 << "DEBUG=" + getNum(DEBUG_flag);
                outfile2 << "\n";

                outfile2 << "DEBUG_COLOR=" + getNum(DEBUG_COLOR_flag);
                outfile2 << "\n";

                outfile2 << "GET_NUMBER=" + getNum(GET_NUMBER_flag);
                outfile2 << "\n";

                outfile2 << "GET_FPS=" + getNum(GET_FPS_flag);
                outfile2 << "\n";

                outfile2 << "CLC_FPS=" + getNum(CLC_FPS_flag);
                outfile2 << "\n";

                outfile2 << "RED_COLOR_THRESH=" + getNum(RED_COLOR_THRESH_value);
                outfile2 << "\n";

                outfile2 << "RED_GRAY_THRESH=" + getNum(RED_GRAY_THRESH_value);
                outfile2 << "\n";

                outfile2 << "BLUE_COLOR_THRESH=" + getNum(BLUE_COLOR_THRESH_value);
                outfile2 << "\n";

                outfile2 << "BLUE_GRAY_THRESH=" + getNum(BLUE_GRAY_THRESH_value);
                outfile2 << "\n";

                outfile2 << "enemyColor=" + enemyColor.toStdString();
                outfile2 << "\n";

                outfile2 << "SVM_thresh=" + getNum(SVM_THRESH_value);

                outfile2.close();



                //保存到初始化定文件中，方便初始化参数
                ofstream outfile3(path.toStdString() + "/UI_file/initPara.txt", ios::trunc);

                outfile3 << getNum(DEBUG_flag);
                outfile3 << "\n";

                outfile3 << getNum(DEBUG_COLOR_flag);
                outfile3 << "\n";

                outfile3 << getNum(GET_NUMBER_flag);
                outfile3 << "\n";

                outfile3 << getNum(GET_FPS_flag);
                outfile3 << "\n";

                outfile3 << getNum(CLC_FPS_flag);
                outfile3 << "\n";

                outfile3 << getNum(RED_COLOR_THRESH_value);
                outfile3 << "\n";

                outfile3 << getNum(RED_GRAY_THRESH_value);
                outfile3 << "\n";

                outfile3 << getNum(BLUE_COLOR_THRESH_value);
                outfile3 << "\n";

                outfile3 << getNum(BLUE_GRAY_THRESH_value);
                outfile3 << "\n";

                outfile3 << getNum(enemyColor).toStdString();
                outfile3 << "\n";

                outfile3 << getNum(SVM_THRESH_value);

                outfile3.close();
            }

            outfile.close();

    }
}

void MainWindow::on_tunePara_stateChanged(int arg1)
{

    if(arg1 == 2)
    {
        tuneParaFlag = "1";

    }
    else if(arg1 == 0)
    {
        tuneParaFlag = "0";

    }

}

void MainWindow::on_DEBUG_stateChanged(int arg1)
{

    if(arg1 == 2)
    {
        DEBUG_flag = "1";

    }
    else if(arg1 == 0)
    {
        DEBUG_flag = "0";

    }

}

void MainWindow::on_DEBUG_COLOR_stateChanged(int arg1)
{

    if(arg1 == 2)
    {
        DEBUG_COLOR_flag = "1";

    }
    else if(arg1 == 0)
    {
        DEBUG_COLOR_flag = "0";

    }

}

void MainWindow::on_GET_NUMBER_stateChanged(int arg1)
{

    if(arg1 == 2)
    {
        GET_NUMBER_flag = "1";

    }
    else if(arg1 == 0)
    {
        GET_NUMBER_flag = "0";

    }

}

void MainWindow::on_GET_FPS_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
        GET_FPS_flag = "1";

    }
    else if(arg1 == 0)
    {
        GET_FPS_flag = "0";

    }

}

void MainWindow::on_CLC_FPS_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
        CLC_FPS_flag = "1";

    }
    else if(arg1 == 0)
    {
        CLC_FPS_flag = "0";

    }

}


void MainWindow::slots_enemyColor(){

    switch(groupButton1->checkedId())
           {
           case 0://red
            enemyColor = "1";
               break;
           case 1://blue
            enemyColor = "0";
               break;
           }

}

void MainWindow::on_SavePara_clicked()
{
    ofstream outfile2("./config.txt", ios::trunc);


     RED_COLOR_THRESH_value = ui->RED_COLOR_THRESH->value();
     RED_GRAY_THRESH_value = ui->RED_GRAY_THRESH->value();
     BLUE_COLOR_THRESH_value = ui->BLUE_COLOR_THRESH->value();
     BLUE_GRAY_THRESH_value = ui->BLUE_GRAY_THRESH->value();
     SVM_THRESH_value =ui->SVM_THRESH->value();
     if (SVM_THRESH_value < 0) SVM_THRESH_value = -SVM_THRESH_value + 255;

    outfile2 << "DEBUG=" + getNum(DEBUG_flag);
    outfile2 << "\n";

    outfile2 << "DEBUG_COLOR=" + getNum(DEBUG_COLOR_flag);
    outfile2 << "\n";

    outfile2 << "GET_NUMBER=" + getNum(GET_NUMBER_flag);
    outfile2 << "\n";

    outfile2 << "GET_FPS=" + getNum(GET_FPS_flag);
    outfile2 << "\n";

    outfile2 << "CLC_FPS=" + getNum(CLC_FPS_flag);
    outfile2 << "\n";

    outfile2 << "RED_COLOR_THRESH=" + getNum(RED_COLOR_THRESH_value);
    outfile2 << "\n";

    outfile2 << "RED_GRAY_THRESH=" + getNum(RED_GRAY_THRESH_value);
    outfile2 << "\n";

    outfile2 << "BLUE_COLOR_THRESH=" + getNum(BLUE_COLOR_THRESH_value);
    outfile2 << "\n";

    outfile2 << "BLUE_GRAY_THRESH=" + getNum(BLUE_GRAY_THRESH_value);
    outfile2 << "\n";

    outfile2 << "enemyColor=" + enemyColor.toStdString();
    outfile2 << "\n";

    outfile2 << "SVM_thresh=" + getNum(SVM_THRESH_value);

    outfile2.close();
}
