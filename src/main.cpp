#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <pthread.h>
#include <time.h>
#include "ArmorDetector.h"
#include "CameraApi.h"
#include "Serialport.h"
#include "Config.h"

#define PTHREAD_CREATE_SUCCESS 0
#define RED 1
#define BLUE 0

#ifdef _WIN64
#pragma comment(lib, "MVCAMSDK_X64.lib")
#else
#pragma comment(lib, "MVCAMSDK.lib")
#endif

using namespace std;
using namespace cv;

Detector detector; //装甲识别类初始化
unsigned char *g_pRgbBuffer;

static void *Get_Armor(void *dstImage);
static void *Get_Video(void *arg);
static void *Show_UI(void *threadarg);

typedef struct thread_data
{
	Mat dstImage;
	pthread_mutex_t lock;
	volatile bool run = FALSE;
} thread_data;

int main()
{
	///////////////////////////////////变量初始化/////////////////////////////////////
	int Ret = 0;
	pthread_t nThreadID[3];
	thread_data TD;
	pthread_mutex_init(&(TD.lock), NULL);
	

	detector.generateSavePath();
	/////////////////////////////////////多线程//////////////////////////////////////
	Ret = pthread_create(&nThreadID[0], NULL, Get_Video, (void *)&TD);
	if (Ret != PTHREAD_CREATE_SUCCESS)
	{
		printf("%s\n", "VIDEO_PTHREAD_CREATE_FILED");
		return -1;
	}
	while (TD.run == FALSE)
		; //等待相机
	Ret = pthread_create(&nThreadID[1], NULL, Get_Armor, (void *)&TD);
	if (Ret != PTHREAD_CREATE_SUCCESS)
	{
		printf("%s\n", "ARMOR_PTHREAD_CREATE_FILED");
		return -1;
	}

#ifdef UI
	// system("../UI/ui.sh");
	system("../bin/UI_DEBUG/UI");
#endif
	// Ret = pthread_create(&nThreadID[2], NULL, Show_UI, (void *)&TD);
	// if (Ret != PTHREAD_CREATE_SUCCESS)
	// {
	// 	printf("%s\n", "ARMOR_PTHREAD_CREATE_FILED");
	// 	return -1;
	// }

	pthread_join(nThreadID[0], NULL);
	pthread_join(nThreadID[1], NULL);

// #ifdef UI
// 	// pthread_join(nThreadID[2], NULL);
// #endif

	pthread_mutex_destroy(&(TD.lock));
	return 0;
}

// static void *Show_UI(void *threadarg){

// 	system("../UI/UI_DEBUG/UI");
// 	return 0;
// }

static void *Get_Armor(void *threadarg)
{
	thread_data *self_data = (thread_data *)threadarg;
	double e1, e2;
	int dmode = 0;
	detector.enemyColor = BLUE;

	//////////////////////////////////串口通信初始化//////////////////////////////////
	//Serialport serp("/dev/ttyTHS2");
	//serp.set_opt(115200, 8, 'N', 1);

	while (TRUE)
	{
		//while (self_data->run == FALSE); //等待相机

		e1 = getTickCount();

		pthread_mutex_lock(&(self_data->lock)); //线程锁
		detector.getSrcImage(self_data->dstImage);
		pthread_mutex_unlock(&(self_data->lock));
		////////////////////////修改颜色///////////////////////
		//serp.readMode(dmode);
		
		detector.getResult();

		double xyz[3];
		if (detector.islost == false)
		{
			cout << "find  the armor successfully!" << endl;
			xyz[0] = detector.target_armor.center.x;
			xyz[1] = detector.target_armor.center.y;
			xyz[2] = detector.target_armor.d_z;
			//cout << "x:" << xy[0] - 640 << "  y:" << 512 - xy[1] << endl;
		}
		else
		{
			cout << "lost the armor!" << endl;
			xyz[0] = 640;
			xyz[1] = 512;
			xyz[2] = 200;
		}
		//serp.sendXYZ(xyz);

		e2 = getTickCount();
#ifdef UI

		if (detector.CLC_FPS_FLAG == 1)
		{
			float time = (e2 - e1) / getTickFrequency();
			float fps = 1 / time;
			cout << "fps:" << fps << endl;
		}
#endif
	}

	pthread_exit(NULL);
	return 0;
}

static void *Get_Video(void *threadarg)
{
	thread_data *self_data = (thread_data *)threadarg;
	double e1, e2;

	//////////////////////////////工业相机参数初始化//////////////////////////////////
	int iCameraCounts = 1; //接入设备数目上限
	int iStatus = -1;
	tSdkCameraDevInfo tCameraEnumList;
	int hCamera;
	tSdkCameraCapbility tCapability;
	tSdkFrameHead sFrameInfo = {0};
	BYTE *m_pbyBuffer;
	int iDisplayFrames = 10000;
	IplImage *iplImage = NULL;
	int channel = 3;

	CameraSdkInit(1);
	iStatus = CameraEnumerateDevice(&tCameraEnumList, &iCameraCounts);
	printf("state = %d\n", iStatus);
	printf("count = %d\n", iCameraCounts);

	CameraInit(&tCameraEnumList, -1, -1, &hCamera);

	//读取相机配置文件，请选择相机相应的配置文件
	char tmp[] = "camera.config";
	char *tmp1 = tmp;
	iStatus = CameraReadParameterFromFile(hCamera, tmp1);

	if (iStatus == CAMERA_STATUS_SUCCESS)
	{
		printf("%s\n", "CAMERA_CONFIG_READ_SUCCESS");
	}
	else
	{
		printf("%s\n", "CAMERA_CONFIG_READ_FAILED");
	}

	CameraGetCapability(hCamera, &tCapability);
	g_pRgbBuffer = (unsigned char *)malloc(tCapability.sResolutionRange.iHeightMax * tCapability.sResolutionRange.iWidthMax * 3);
	CameraPlay(hCamera);
	CameraSetIspOutFormat(hCamera, CAMERA_MEDIA_TYPE_BGR8);

	//相机开始采集
	while (TRUE)
	{
		//选用其一
		if (CameraGetImageBuffer(hCamera, &sFrameInfo, &m_pbyBuffer, 1000) == CAMERA_STATUS_SUCCESS)
		//if (CameraGetImageBufferPriority(hCamera, &sFrameInfo, &m_pbyBuffer, 1000, CAMERA_GET_IMAGE_PRIORITY_NEWEST) == CAMERA_STATUS_SUCCESS)
		{
			e1 = getTickCount();

			iStatus = CameraImageProcess(hCamera, m_pbyBuffer, g_pRgbBuffer, &sFrameInfo);
			//获取图像
			if (iStatus == CAMERA_STATUS_SUCCESS)
			{
				Mat Image(cvSize(sFrameInfo.iWidth, sFrameInfo.iHeight), sFrameInfo.uiMediaType == CAMERA_MEDIA_TYPE_MONO8 ? CV_8UC1 : CV_8UC3, g_pRgbBuffer);
				//flip(Image, Image, 0);//若图像颠倒，请注释本行

				pthread_mutex_lock(&(self_data->lock)); //线程锁
				Image.copyTo(self_data->dstImage);
				pthread_mutex_unlock(&(self_data->lock));
				self_data->run = TRUE;

				//imshow("x", Image);
				//waitKey(1);
			}

			CameraReleaseImageBuffer(hCamera, m_pbyBuffer);

			e2 = getTickCount();
		}
		else
		{
			self_data->run = FALSE;
		}
#ifdef UI
		if (detector.GET_FPS_FLAG == 1)
		{
			float time = (e2 - e1) / getTickFrequency();
			float fps = 1 / time;
			cout << "fps:" << fps << endl;
			//cout << "time:" << time*1000 <<"ms"<< endl;
		}

#endif
	}
	CameraUnInit(hCamera);
	//释放相机
	std::free(g_pRgbBuffer);
	std::free(m_pbyBuffer);

	pthread_exit(NULL);
	return 0;
}
