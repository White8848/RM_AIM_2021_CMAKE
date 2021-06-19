#pragma once
#ifndef _CAMERA_DEFINE_H_
#define _CAMERA_DEFINE_H_

#include "CameraStatus.h"

#define MAX_CROSS_LINE 9

//Ïà»úµÄŸä±úÀàÐÍ¶šÒå
typedef int CameraHandle;
typedef int INT;
typedef int LONG;
typedef unsigned int UINT;
typedef unsigned long long UINT64;
typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned int DWORD;
typedef void* PVOID;
typedef void* HWND;
typedef char* LPCTSTR;
typedef unsigned short USHORT;
typedef short SHORT;
 typedef unsigned char* LPBYTE;
typedef char CHAR;
typedef char TCHAR;
typedef  unsigned short WORD;
typedef INT HANDLE;
typedef void VOID;
typedef unsigned int ULONG;
typedef void* LPVOID;
typedef unsigned char UCHAR;
typedef void* HMODULE;

#define TRUE 1
#define FALSE 0
//ÍŒÏñ²é±í±ä»»µÄ·œÊœ
typedef enum
{
    LUTMODE_PARAM_GEN=0,//Íš¹ýµ÷œÚ²ÎÊý¶¯Ì¬Éú³ÉLUT±í
    LUTMODE_PRESET,     //Ê¹ÓÃÔ€ÉèµÄLUT±í
    LUTMODE_USER_DEF    //Ê¹ÓÃÓÃ»§×Ô¶šÒåµÄLUT±í
}emSdkLutMode;

//Ïà»úµÄÊÓÆµÁ÷¿ØÖÆ
typedef enum
{
    RUNMODE_PLAY=0,    //Õý³£Ô€ÀÀ£¬²¶»ñµœÍŒÏñŸÍÏÔÊŸ¡££šÈç¹ûÏà»úŽŠÓÚŽ¥·¢Ä£Êœ£¬Ôò»áµÈŽýŽ¥·¢Ö¡µÄµœÀŽ£©
    RUNMODE_PAUSE,     //ÔÝÍ££¬»áÔÝÍ£Ïà»úµÄÍŒÏñÊä³ö£¬Í¬Ê±Ò²²»»áÈ¥²¶»ñÍŒÏñ
    RUNMODE_STOP       //Í£Ö¹Ïà»ú¹€×÷¡£·Ž³õÊŒ»¯ºó£¬Ïà»úŸÍŽŠÓÚÍ£Ö¹Ä£Êœ
}emSdkRunMode;

//SDKÄÚ²¿ÏÔÊŸœÓ¿ÚµÄÏÔÊŸ·œÊœ
typedef enum
{
    DISPLAYMODE_SCALE=0, //Ëõ·ÅÏÔÊŸÄ£Êœ£¬Ëõ·ÅµœÏÔÊŸ¿ØŒþµÄ³ßŽç
    DISPLAYMODE_REAL     //1:1ÏÔÊŸÄ£Êœ£¬µ±ÍŒÏñ³ßŽçŽóÓÚÏÔÊŸ¿ØŒþµÄ³ßŽçÊ±£¬Ö»ÏÔÊŸŸÖ²¿
}emSdkDisplayMode;

//ÂŒÏñ×ŽÌ¬
typedef enum
{
  RECORD_STOP = 0,  //Í£Ö¹
  RECORD_START,     //ÂŒÏñÖÐ
  RECORD_PAUSE      //ÔÝÍ£
}emSdkRecordMode;

//ÍŒÏñµÄŸµÏñ²Ù×÷
typedef enum
{
    MIRROR_DIRECTION_HORIZONTAL = 0,//Ë®ÆœŸµÏñ
    MIRROR_DIRECTION_VERTICAL       //Ž¹Ö±ŸµÏñ
}emSdkMirrorDirection;

/// @ingroup MV_ENUM_TYPE
/// \~chinese ÍŒÏñµÄÐý×ª²Ù×÷
/// \~english Rotation of the image
typedef enum
{
    ROTATE_DIRECTION_0=0,		///< \~chinese ²»Ðý×ª		\~english Do not rotate
    ROTATE_DIRECTION_90=1,		///< \~chinese ÄæÊ±Õë90¶È	\~english Counterclockwise 90 degrees
    ROTATE_DIRECTION_180=2,		///< \~chinese ÄæÊ±Õë180¶È	\~english Counterclockwise 180 degrees
    ROTATE_DIRECTION_270=3,		///< \~chinese ÄæÊ±Õë270¶È	\~english Counterclockwise 270 degrees
}emSdkRotateDirection;

//Ïà»úÊÓÆµµÄÖ¡ÂÊ
typedef enum
{
    FRAME_SPEED_LOW = 0,  //µÍËÙÄ£Êœ
    FRAME_SPEED_NORMAL,   //ÆÕÍšÄ£Êœ
    FRAME_SPEED_HIGH,     //žßËÙÄ£Êœ(ÐèÒªœÏžßµÄŽ«ÊäŽø¿í,¶àÉè±ž¹²ÏíŽ«ÊäŽø¿íÊ±»á¶ÔÖ¡ÂÊµÄÎÈ¶šÐÔÓÐÓ°Ïì)
    FRAME_SPEED_SUPER     //³¬žßËÙÄ£Êœ(ÐèÒªœÏžßµÄŽ«ÊäŽø¿í,¶àÉè±ž¹²ÏíŽ«ÊäŽø¿íÊ±»á¶ÔÖ¡ÂÊµÄÎÈ¶šÐÔÓÐÓ°Ïì)
}emSdkFrameSpeed;

//±£ŽæÎÄŒþµÄžñÊœÀàÐÍ
typedef enum
{
    FILE_JPG = 1,//JPG
    FILE_BMP = 2,//BMP
    FILE_RAW = 4,//Ïà»úÊä³öµÄbayeržñÊœÎÄŒþ,¶ÔÓÚ²»Ö§³ÖbayeržñÊœÊä³öÏà»ú£¬ÎÞ·š±£ŽæÎªžÃžñÊœ
    FILE_PNG = 8, //PNG
    FILE_BMP_8BIT = 16,	  ///< \~chinese BMP 8bit		\~english BMP 8bit
    FILE_PNG_8BIT = 32,   ///< \~chinese PNG 8bit		\~english PNG 8bit
      FILE_RAW_16BIT = 64,	///< \~chinese RAW 16bit	\~english RAW 16bit
}emSdkFileType;

//Ïà»úÖÐµÄÍŒÏñŽ«žÐÆ÷µÄ¹€×÷Ä£Êœ
typedef enum
{
    CONTINUATION = 0,//Á¬Ðø²ÉŒ¯Ä£Êœ
    SOFT_TRIGGER,    //ÈíŒþŽ¥·¢Ä£Êœ£¬ÓÉÈíŒþ·¢ËÍÖžÁîºó£¬Ž«žÐÆ÷¿ªÊŒ²ÉŒ¯Öž¶šÖ¡ÊýµÄÍŒÏñ£¬²ÉŒ¯Íê³Éºó£¬Í£Ö¹Êä³ö
    EXTERNAL_TRIGGER //Ó²ŒþŽ¥·¢Ä£Êœ£¬µ±œÓÊÕµœÍâ²¿ÐÅºÅ£¬Ž«žÐÆ÷¿ªÊŒ²ÉŒ¯Öž¶šÖ¡ÊýµÄÍŒÏñ£¬²ÉŒ¯Íê³Éºó£¬Í£Ö¹Êä³ö
} emSdkSnapMode;

//×Ô¶¯ÆØ¹âÊ±¿¹ÆµÉÁµÄÆµÉÁ
typedef enum
{
    LIGHT_FREQUENCY_50HZ = 0,//50HZ,Ò»°ãµÄµÆ¹â¶ŒÊÇ50HZ
    LIGHT_FREQUENCY_60HZ     //60HZ,Ö÷ÒªÊÇÖžÏÔÊŸÆ÷µÄ
}emSdkLightFrequency;

//Ïà»úµÄÅäÖÃ²ÎÊý£¬·ÖÎªA,B,C,D 4×éœøÐÐ±£Žæ¡£
typedef enum
{
    PARAMETER_TEAM_DEFAULT = 0xff,
    PARAMETER_TEAM_A = 0,
    PARAMETER_TEAM_B = 1,
    PARAMETER_TEAM_C = 2,
    PARAMETER_TEAM_D = 3
}emSdkParameterTeam;


/*emSdkParameterMode Ïà»ú²ÎÊýŒÓÔØÄ£Êœ£¬²ÎÊýŒÓÔØ·ÖÎªŽÓÎÄŒþºÍŽÓÉè±žŒÓÔØÁœÖÖ·œÊœ

PARAM_MODE_BY_MODEL:ËùÓÐÍ¬ÐÍºÅµÄÏà»ú¹²ÓÃABCDËÄ×é²ÎÊýÎÄŒþ¡£ÐÞžÄ
             Ò»ÌšÏà»úµÄ²ÎÊýÎÄŒþ£¬»áÓ°ÏìµœÕûžöÍ¬ÐÍºÅµÄ
             Ïà»ú²ÎÊýŒÓÔØ¡£

PARAM_MODE_BY_NAME:ËùÓÐÉè±žÃûÏàÍ¬µÄÏà»ú£¬¹²ÓÃABCDËÄ×é²ÎÊýÎÄŒþ¡£
         Ä¬ÈÏÇé¿öÏÂ£¬µ±µçÄÔÉÏÖ»œÓÁËÄ³ÐÍºÅÒ»ÌšÏà»úÊ±£¬
         Éè±žÃû¶ŒÊÇÒ»ÑùµÄ£¬¶øÄúÏ£ÍûÄ³Ò»ÌšÏà»úÄÜ¹»ŒÓÔØ
         ²»Í¬µÄ²ÎÊýÎÄŒþ£¬Ôò¿ÉÒÔÍš¹ýÐÞžÄÆäÉè±žÃûµÄ·œÊœ
         ÀŽÈÃÆäŒÓÔØÖž¶šµÄ²ÎÊýÎÄŒþ¡£

PARAM_MODE_BY_SN:Ïà»ú°ŽÕÕ×ÔŒºµÄÎšÒ»ÐòÁÐºÅÀŽŒÓÔØABCDËÄ×é²ÎÊýÎÄŒþ£¬
         ÐòÁÐºÅÔÚ³ö³§Ê±ÒÑŸ­¹Ì»¯ÔÚÏà»úÄÚ£¬Ã¿ÌšÏà»úµÄÐòÁÐºÅ
         ¶Œ²»ÏàÍ¬£¬Íš¹ýÕâÖÖ·œÊœ£¬Ã¿ÌšÏà»úµÄ²ÎÊýÎÄŒþ¶ŒÊÇ¶ÀÁ¢µÄ¡£

Äú¿ÉÒÔžùŸÝ×ÔŒºµÄÊ¹ÓÃ»·Ÿ³£¬Áé»îÊ¹ÓÃÒÔÉÏŒžÖÖ·œÊœŒÓÔØ²ÎÊý¡£ÀýÈç£¬ÒÔ
MV-U300ÎªÀý£¬ÄúÏ£Íû¶àÌšžÃÐÍºÅµÄÏà»úÔÚÄúµÄ µçÄÔÉÏ¶Œ¹²ÓÃ4×é²ÎÊý£¬ÄÇÃŽŸÍ
Ê¹ÓÃPARAM_MODE_BY_MODEL·œÊœ;Èç¹ûÄúÏ£ÍûÆäÖÐÄ³Ò»Ìš»òÕßÄ³ŒžÌšMV-U300ÄÜ
Ê¹ÓÃ×ÔŒº²ÎÊýÎÄŒþ¶øÆäÓàµÄMV-U300ÓÖÒªÊ¹ÓÃÏàÍ¬µÄ²ÎÊýÎÄŒþ£¬ÄÇÃŽÊ¹ÓÃ
PARAM_MODE_BY_NAME·œÊœ;Èç¹ûÄúÏ£ÍûÃ¿ÌšMV-U300¶ŒÊ¹ÓÃ²»Í¬µÄ²ÎÊýÎÄŒþ£¬ÄÇÃŽ
Ê¹ÓÃPARAM_MODE_BY_SN·œÊœ¡£
²ÎÊýÎÄŒþŽæÔÚ°²×°Ä¿ÂŒµÄ \Camera\Configs Ä¿ÂŒÏÂ£¬ÒÔconfigÎªºó×ºÃûµÄÎÄŒþ¡£
*/
typedef enum
{
  PARAM_MODE_BY_MODEL = 0,  //žùŸÝÏà»úÐÍºÅÃûŽÓÎÄŒþÖÐŒÓÔØ²ÎÊý£¬ÀýÈçMV-U300
  PARAM_MODE_BY_NAME,       //žùŸÝÉè±žêÇ³Æ(tSdkCameraDevInfo.acFriendlyName)ŽÓÎÄŒþÖÐŒÓÔØ²ÎÊý£¬ÀýÈçMV-U300,žÃêÇ³Æ¿É×Ô¶šÒå
  PARAM_MODE_BY_SN,         //žùŸÝÉè±žµÄÎšÒ»ÐòÁÐºÅŽÓÎÄŒþÖÐŒÓÔØ²ÎÊý£¬ÐòÁÐºÅÔÚ³ö³§Ê±ÒÑŸ­ÐŽÈëÉè±ž£¬Ã¿ÌšÏà»úÓµÓÐ²»Í¬µÄÐòÁÐºÅ¡£
  PARAM_MODE_IN_DEVICE      //ŽÓÉè±žµÄ¹ÌÌ¬ŽæŽ¢Æ÷ÖÐŒÓÔØ²ÎÊý¡£²»ÊÇËùÓÐµÄÐÍºÅ¶ŒÖ§³ÖŽÓÏà»úÖÐ¶ÁÐŽ²ÎÊý×é£¬ÓÉtSdkCameraCapbility.bParamInDeviceŸö¶š
}emSdkParameterMode;


//SDKÉú³ÉµÄÏà»úÅäÖÃÒ³ÃæÑÚÂëÖµ
typedef enum
{
  PROP_SHEET_INDEX_EXPOSURE = 0,
  PROP_SHEET_INDEX_ISP_COLOR,
  PROP_SHEET_INDEX_ISP_LUT,
  PROP_SHEET_INDEX_ISP_SHAPE,
  PROP_SHEET_INDEX_VIDEO_FORMAT,
  PROP_SHEET_INDEX_RESOLUTION,
  PROP_SHEET_INDEX_IO_CTRL,
  PROP_SHEET_INDEX_TRIGGER_SET,
  PROP_SHEET_INDEX_OVERLAY,
  PROP_SHEET_INDEX_DEVICE_INFO,
  PROP_SHEET_INDEX_WDR,
  PROP_SHEET_INDEX_MULTI_EXPOSURE
}emSdkPropSheetMask;

//SDKÉú³ÉµÄÏà»úÅäÖÃÒ³ÃæµÄ»Øµ÷ÏûÏ¢ÀàÐÍ
typedef enum
{
  SHEET_MSG_LOAD_PARAM_DEFAULT = 0, //²ÎÊý±»»ÖžŽ³ÉÄ¬ÈÏºó£¬Ž¥·¢žÃÏûÏ¢
  SHEET_MSG_LOAD_PARAM_GROUP,       //ŒÓÔØÖž¶š²ÎÊý×é£¬Ž¥·¢žÃÏûÏ¢
  SHEET_MSG_LOAD_PARAM_FROMFILE,    //ŽÓÖž¶šÎÄŒþŒÓÔØ²ÎÊýºó£¬Ž¥·¢žÃÏûÏ¢
  SHEET_MSG_SAVE_PARAM_GROUP        //µ±Ç°²ÎÊý×é±»±£ŽæÊ±£¬Ž¥·¢žÃÏûÏ¢
}emSdkPropSheetMsg;

//¿ÉÊÓ»¯Ñ¡Ôñ²Î¿ŒŽ°¿ÚµÄÀàÐÍ
typedef enum
{
  REF_WIN_AUTO_EXPOSURE = 0,
  REF_WIN_WHITE_BALANCE,
}emSdkRefWinType;

//¿ÉÊÓ»¯Ñ¡Ôñ²Î¿ŒŽ°¿ÚµÄÀàÐÍ
typedef enum
{
  RES_MODE_PREVIEW = 0,
  RES_MODE_SNAPSHOT,
}emSdkResolutionMode;

//°×ÆœºâÊ±É«ÎÂÄ£Êœ
typedef enum
{
  CT_MODE_AUTO = 0, //×Ô¶¯Ê¶±ðÉ«ÎÂ
  CT_MODE_PRESET,   //Ê¹ÓÃÖž¶šµÄÔ€ÉèÉ«ÎÂ
  CT_MODE_USER_DEF  //×Ô¶šÒåÉ«ÎÂ(ÔöÒæºÍŸØÕó)
}emSdkClrTmpMode;

//LUTµÄÑÕÉ«ÍšµÀ
typedef enum
{
  LUT_CHANNEL_ALL = 0,//R,B,GÈýÍšµÀÍ¬Ê±µ÷œÚ
  LUT_CHANNEL_RED,    //ºìÉ«ÍšµÀ
  LUT_CHANNEL_GREEN,  //ÂÌÉ«ÍšµÀ
  LUT_CHANNEL_BLUE,   //À¶É«ÍšµÀ
}emSdkLutChannel;

//ISPŽŠÀíµ¥Ôª
typedef enum
{
  ISP_PROCESSSOR_PC = 0,//Ê¹ÓÃPCµÄÈíŒþISPÄ£¿é
  ISP_PROCESSSOR_DEVICE //Ê¹ÓÃÏà»ú×ÔŽøµÄÓ²ŒþISPÄ£¿é
}emSdkIspProcessor;

//ÉÁ¹âµÆÐÅºÅ¿ØÖÆ·œÊœ
typedef enum
{
  STROBE_SYNC_WITH_TRIG_AUTO = 0,    //ºÍŽ¥·¢ÐÅºÅÍ¬²œ£¬Ž¥·¢ºó£¬Ïà»úœøÐÐÆØ¹âÊ±£¬×Ô¶¯Éú³ÉSTROBEÐÅºÅ¡£ŽËÊ±£¬ÓÐÐ§Œ«ÐÔ¿ÉÉèÖÃ(CameraSetStrobePolarity)¡£
  STROBE_SYNC_WITH_TRIG_MANUAL,      //ºÍŽ¥·¢ÐÅºÅÍ¬²œ£¬Ž¥·¢ºó£¬STROBEÑÓÊ±Öž¶šµÄÊ±Œäºó(CameraSetStrobeDelayTime)£¬ÔÙ³ÖÐøÖž¶šÊ±ŒäµÄÂö³å(CameraSetStrobePulseWidth)£¬ÓÐÐ§Œ«ÐÔ¿ÉÉèÖÃ(CameraSetStrobePolarity)¡£
  STROBE_ALWAYS_HIGH,                //ÊŒÖÕÎªžß£¬ºöÂÔSTROBEÐÅºÅµÄÆäËûÉèÖÃ
  STROBE_ALWAYS_LOW                  //ÊŒÖÕÎªµÍ£¬ºöÂÔSTROBEÐÅºÅµÄÆäËûÉèÖÃ
}emStrobeControl;

//Ó²ŒþÍâŽ¥·¢µÄÐÅºÅÖÖÀà
typedef enum
{
  EXT_TRIG_LEADING_EDGE = 0,     //ÉÏÉýÑØŽ¥·¢£¬Ä¬ÈÏÎªžÃ·œÊœ
  EXT_TRIG_TRAILING_EDGE,        //ÏÂœµÑØŽ¥·¢
  EXT_TRIG_HIGH_LEVEL,           //žßµçÆœŽ¥·¢,µçÆœ¿í¶ÈŸö¶šÆØ¹âÊ±Œä£¬œö²¿·ÖÐÍºÅµÄÏà»úÖ§³ÖµçÆœŽ¥·¢·œÊœ¡£
  EXT_TRIG_LOW_LEVEL             //µÍµçÆœŽ¥·¢,
}emExtTrigSignal;

//Ó²ŒþÍâŽ¥·¢Ê±µÄ¿ìÃÅ·œÊœ
typedef enum
{
  EXT_TRIG_EXP_STANDARD = 0,     //±ê×Œ·œÊœ£¬Ä¬ÈÏÎªžÃ·œÊœ¡£
  EXT_TRIG_EXP_GRR,              //È«ŸÖžŽÎ»·œÊœ£¬²¿·Ö¹ö¶¯¿ìÃÅµÄCMOSÐÍºÅµÄÏà»úÖ§³ÖžÃ·œÊœ£¬ÅäºÏÍâ²¿»úÐµ¿ìÃÅ£¬¿ÉÒÔŽïµœÈ«ŸÖ¿ìÃÅµÄÐ§¹û£¬ÊÊºÏÅÄžßËÙÔË¶¯µÄÎïÌå
}emExtTrigShutterMode;

// GPIOÄ£Êœ
typedef enum
{
  IOMODE_TRIG_INPUT=0,		    ///< \~chinese Ž¥·¢ÊäÈë \~english Trigger input
  IOMODE_STROBE_OUTPUT=1,		  ///< \~chinese ÉÁ¹âµÆÊä³ö \~english Strobe output
  IOMODE_GP_INPUT=2,			    ///< \~chinese ÍšÓÃÐÍÊäÈë \~english Universal input
  IOMODE_GP_OUTPUT=3,			    ///< \~chinese ÍšÓÃÐÍÊä³ö \~english Universal output
  IOMODE_PWM_OUTPUT=4,		    ///< \~chinese PWMÐÍÊä³ö \~english PWM output
  IOMODE_ROTARYENC_INPUT=5,   ///< \~chinese ±àÂëÆ÷ÊäÈë \~english rotary input
}emCameraGPIOMode;

/// @ingroup MV_ENUM_TYPE
/// \~chinese GPIO žñÊœ
/// \~english GPIO Format
typedef enum
{
    IOFORMAT_SINGLE=0,			///< \~chinese µ¥¶Ë  \~english single ended
    IOFORMAT_RS422=1,			  ///< \~chinese ²î·ÖRS422 \~english Differential RS422
    IOFORMAT_RS422_TERM=2,	///< \~chinese ²î·ÖRS422ŽøÖÕ¶Ëµç×è \~english Differential RS422 and Termination Enable
}emCameraGPIOFormat;

/// @ingroup MV_ENUM_TYPE
/// \~chinese È¡ÍŒÓÅÏÈŒ¶
/// \~english Get Image priority
typedef enum
{
    CAMERA_GET_IMAGE_PRIORITY_OLDEST=0,		///< \~chinese »ñÈ¡»ºŽæÖÐ×îŸÉµÄÒ»Ö¡ \~english	Get the oldest frame in the cache
    CAMERA_GET_IMAGE_PRIORITY_NEWEST=1,		///< \~chinese »ñÈ¡»ºŽæÖÐ×îÐÂµÄÒ»Ö¡£š±ÈŽËÖ¡ŸÉµÄœ«È«²¿¶ªÆú£© \~english Get the latest frame in the cache (older than this frame will be discarded)

    /// \~chinese ¶ªÆú»ºŽæÖÐµÄËùÓÐÖ¡£¬²¢ÇÒÈç¹ûŽË¿ÌÏà»úÕýÔÚÆØ¹â»òŽ«Êäœ«»á±»Á¢ŒŽŽò¶Ï£¬µÈŽýœÓÊÕÏÂÒ»Ö¡
    /// \note Ä³Ð©ÐÍºÅµÄÏà»ú²»Ö§³ÖŽË¹ŠÄÜ£¬¶ÔÓÚ²»Ö§³ÖŽË¹ŠÄÜµÄÏà»úÕâžö±êÖŸÏàµ±ÓÚ@link #CAMERA_GET_IMAGE_PRIORITY_OLDEST @endlink
    /// \~english All frames in the cache are discarded, and if the camera is now being exposed or transmitted it will be immediately interrupted, waiting to receive the next frame
    /// \note Some models do not support this feature. For cameras that do not support this feature this flag is equivalent to @link #CAMERA_GET_IMAGE_PRIORITY_OLDEST @endlink
    CAMERA_GET_IMAGE_PRIORITY_NEXT=2,
}emCameraGetImagePriority;

/// @ingroup MV_ENUM_TYPE
/// \~chinese ÈíŽ¥·¢¹ŠÄÜ±êÖŸ
/// \~english Soft trigger function flag
typedef enum
{
    CAMERA_ST_CLEAR_BUFFER_BEFORE	= 0x1,	///< \~chinese ÔÚÈíŽ¥·¢Ö®Ç°ÏÈÇå¿ÕÏà»úÒÑ»ºŽæµÄÖ¡ \~english Empty camera-cached frames before soft triggering
}emCameraSoftTriggerExFlags;

//Ïà»úµÄÉè±žÐÅÏ¢
typedef struct
{
    char acProductSeries[32];   // ²úÆ·ÏµÁÐ
    char acProductName[32];     // ²úÆ·Ãû³Æ
    char acFriendlyName[32];    // ²úÆ·êÇ³Æ£¬ÓÃ»§¿É×Ô¶šÒåžÄêÇ³Æ£¬±£ŽæÔÚÏà»úÄÚ£¬ÓÃÓÚÇø·Ö¶àžöÏà»úÍ¬Ê±Ê¹ÓÃ,¿ÉÒÔÓÃCameraSetFriendlyNameœÓ¿ÚžÄ±äžÃêÇ³Æ£¬Éè±žÖØÆôºóÉúÐ§¡£
    char acLinkName[32];        // ÄÚºË·ûºÅÁ¬œÓÃû£¬ÄÚ²¿Ê¹ÓÃ
    char acDriverVersion[32];   // Çý¶¯°æ±Ÿ
    char acSensorType[32];      // sensorÀàÐÍ
    char acPortType[32];        // œÓ¿ÚÀàÐÍ
    char acSn[32];              // ²úÆ·ÎšÒ»ÐòÁÐºÅ
    UINT uInstance;             // žÃÐÍºÅÏà»úÔÚžÃµçÄÔÉÏµÄÊµÀýË÷ÒýºÅ£¬ÓÃÓÚÇø·ÖÍ¬ÐÍºÅ¶àÏà»ú
} tSdkCameraDevInfo;

#define EXT_TRIG_MASK_GRR_SHUTTER  1	///< \~chinese ¿ìÃÅÖ§³ÖGRRÄ£Êœ \~english Shutter supports GRR mode
#define EXT_TRIG_MASK_LEVEL_MODE   2	///< \~chinese Ö§³ÖµçÆœŽ¥·¢ \~english Support level trigger
#define EXT_TRIG_MASK_DOUBLE_EDGE  4	///< \~chinese Ö§³ÖË«±ßÑØŽ¥·¢ \~english Supports bilateral triggering

//tSdkResolutionRangeœá¹¹ÌåÖÐSKIP¡¢ BIN¡¢RESAMPLEÄ£ÊœµÄÑÚÂëÖµ
#define MASK_2X2_HD     (1<<0)    //Ó²ŒþSKIP¡¢BIN¡¢ÖØ²ÉÑù 2X2
#define MASK_3X3_HD     (1<<1)
#define MASK_4X4_HD     (1<<2)
#define MASK_5X5_HD     (1<<3)
#define MASK_6X6_HD     (1<<4)
#define MASK_7X7_HD     (1<<5)
#define MASK_8X8_HD     (1<<6)
#define MASK_9X9_HD     (1<<7)
#define MASK_10X10_HD   (1<<8)
#define MASK_11X11_HD   (1<<9)
#define MASK_12X12_HD   (1<<10)
#define MASK_13X13_HD   (1<<11)
#define MASK_14X14_HD   (1<<12)
#define MASK_15X15_HD   (1<<13)
#define MASK_16X16_HD   (1<<14)
#define MASK_17X17_HD   (1<<15)
#define MASK_2X2_SW     (1<<16)   //Ó²ŒþSKIP¡¢BIN¡¢ÖØ²ÉÑù 2X2
#define MASK_3X3_SW     (1<<17)
#define MASK_4X4_SW     (1<<18)
#define MASK_5X5_SW     (1<<19)
#define MASK_6X6_SW     (1<<20)
#define MASK_7X7_SW     (1<<21)
#define MASK_8X8_SW     (1<<22)
#define MASK_9X9_SW     (1<<23)
#define MASK_10X10_SW   (1<<24)
#define MASK_11X11_SW   (1<<25)
#define MASK_12X12_SW   (1<<26)
#define MASK_13X13_SW   (1<<27)
#define MASK_14X14_SW   (1<<28)
#define MASK_15X15_SW   (1<<29)
#define MASK_16X16_SW   (1<<30)
#define MASK_17X17_SW   (1<<31)

//Ïà»úµÄ·Ö±æÂÊÉè¶š·¶Î§£¬ÓÃÓÚ¹¹ŒþUI
typedef struct
{
  INT iHeightMax;             //ÍŒÏñ×îŽóžß¶È
  INT iHeightMin;             //ÍŒÏñ×îÐ¡žß¶È
  INT iWidthMax;              //ÍŒÏñ×îŽó¿í¶È
  INT iWidthMin;              //ÍŒÏñ×îÐ¡¿í¶È
  UINT uSkipModeMask;         //SKIPÄ£ÊœÑÚÂë£¬Îª0£¬±íÊŸ²»Ö§³ÖSKIP ¡£bit0Îª1,±íÊŸÖ§³ÖSKIP 2x2 ;bit1Îª1£¬±íÊŸÖ§³ÖSKIP 3x3....
  UINT uBinSumModeMask;       //BIN(ÇóºÍ)Ä£ÊœÑÚÂë£¬Îª0£¬±íÊŸ²»Ö§³ÖBIN ¡£bit0Îª1,±íÊŸÖ§³ÖBIN 2x2 ;bit1Îª1£¬±íÊŸÖ§³ÖBIN 3x3....
  UINT uBinAverageModeMask;   //BIN(ÇóŸùÖµ)Ä£ÊœÑÚÂë£¬Îª0£¬±íÊŸ²»Ö§³ÖBIN ¡£bit0Îª1,±íÊŸÖ§³ÖBIN 2x2 ;bit1Îª1£¬±íÊŸÖ§³ÖBIN 3x3....
  UINT uResampleMask;         //Ó²ŒþÖØ²ÉÑùµÄÑÚÂë
} tSdkResolutionRange;


//Ïà»úµÄ·Ö±æÂÊÃèÊö
typedef struct
{
  INT     iIndex;             // Ë÷ÒýºÅ£¬[0,N]±íÊŸÔ€ÉèµÄ·Ö±æÂÊ(N ÎªÔ€Éè·Ö±æÂÊµÄ×îŽóžöÊý£¬Ò»°ã²»³¬¹ý20),OXFF ±íÊŸ×Ô¶šÒå·Ö±æÂÊ(ROI)
  char    acDescription[32];  // žÃ·Ö±æÂÊµÄÃèÊöÐÅÏ¢¡£œöÔ€Éè·Ö±æÂÊÊ±žÃÐÅÏ¢ÓÐÐ§¡£×Ô¶šÒå·Ö±æÂÊ¿ÉºöÂÔžÃÐÅÏ¢
  UINT    uBinSumMode;        // BIN(ÇóºÍ)µÄÄ£Êœ,·¶Î§²»ÄÜ³¬¹ýtSdkResolutionRangeÖÐuBinSumModeMask
  UINT    uBinAverageMode;    // BIN(ÇóŸùÖµ)µÄÄ£Êœ,·¶Î§²»ÄÜ³¬¹ýtSdkResolutionRangeÖÐuBinAverageModeMask
  UINT    uSkipMode;          // ÊÇ·ñSKIPµÄ³ßŽç£¬Îª0±íÊŸœûÖ¹SKIPÄ£Êœ£¬·¶Î§²»ÄÜ³¬¹ýtSdkResolutionRangeÖÐuSkipModeMask
  UINT    uResampleMask;      // Ó²ŒþÖØ²ÉÑùµÄÑÚÂë
  INT     iHOffsetFOV;        // ²ÉŒ¯ÊÓ³¡Ïà¶ÔÓÚSensor×îŽóÊÓ³¡×óÉÏœÇµÄŽ¹Ö±Æ«ÒÆ
  INT     iVOffsetFOV;        // ²ÉŒ¯ÊÓ³¡Ïà¶ÔÓÚSensor×îŽóÊÓ³¡×óÉÏœÇµÄË®ÆœÆ«ÒÆ
  INT     iWidthFOV;          // ²ÉŒ¯ÊÓ³¡µÄ¿í¶È
  INT     iHeightFOV;         // ²ÉŒ¯ÊÓ³¡µÄžß¶È
  INT     iWidth;             // Ïà»ú×îÖÕÊä³öµÄÍŒÏñµÄ¿í¶È
  INT     iHeight;            // Ïà»ú×îÖÕÊä³öµÄÍŒÏñµÄžß¶È
  INT     iWidthZoomHd;       // Ó²ŒþËõ·ÅµÄ¿í¶È,²»ÐèÒªœøÐÐŽË²Ù×÷µÄ·Ö±æÂÊ£¬ŽË±äÁ¿ÉèÖÃÎª0.
  INT     iHeightZoomHd;      // Ó²ŒþËõ·ÅµÄžß¶È,²»ÐèÒªœøÐÐŽË²Ù×÷µÄ·Ö±æÂÊ£¬ŽË±äÁ¿ÉèÖÃÎª0.
  INT     iWidthZoomSw;       // ÈíŒþËõ·ÅµÄ¿í¶È,²»ÐèÒªœøÐÐŽË²Ù×÷µÄ·Ö±æÂÊ£¬ŽË±äÁ¿ÉèÖÃÎª0.
  INT     iHeightZoomSw;      // ÈíŒþËõ·ÅµÄžß¶È,²»ÐèÒªœøÐÐŽË²Ù×÷µÄ·Ö±æÂÊ£¬ŽË±äÁ¿ÉèÖÃÎª0.
} tSdkImageResolution;

//Ïà»ú°×ÆœºâÉ«ÎÂÄ£ÊœÃèÊöÐÅÏ¢
typedef struct
{
    INT  iIndex;            // Ä£ÊœË÷ÒýºÅ
    char acDescription[32]; // ÃèÊöÐÅÏ¢
} tSdkColorTemperatureDes;

//Ïà»úÖ¡ÂÊÃèÊöÐÅÏ¢
typedef struct
{
    INT  iIndex;             // Ö¡ÂÊË÷ÒýºÅ£¬Ò»°ã0¶ÔÓŠÓÚµÍËÙÄ£Êœ£¬1¶ÔÓŠÓÚÆÕÍšÄ£Êœ£¬2¶ÔÓŠÓÚžßËÙÄ£Êœ
    char acDescription[32];  // ÃèÊöÐÅÏ¢
} tSdkFrameSpeed;

//Ïà»úÆØ¹â¹ŠÄÜ·¶Î§¶šÒå
typedef struct
{
    UINT  uiTargetMin;      //×Ô¶¯ÆØ¹âÁÁ¶ÈÄ¿±ê×îÐ¡Öµ
    UINT  uiTargetMax;      //×Ô¶¯ÆØ¹âÁÁ¶ÈÄ¿±ê×îŽóÖµ
    UINT  uiAnalogGainMin;  //Ä£ÄâÔöÒæµÄ×îÐ¡Öµ£¬µ¥Î»ÎªfAnalogGainStepÖÐ¶šÒå
    UINT  uiAnalogGainMax;  //Ä£ÄâÔöÒæµÄ×îŽóÖµ£¬µ¥Î»ÎªfAnalogGainStepÖÐ¶šÒå
    float fAnalogGainStep;  //Ä£ÄâÔöÒæÃ¿ÔöŒÓ1£¬¶ÔÓŠµÄÔöŒÓµÄ·ÅŽó±¶Êý¡£ÀýÈç£¬uiAnalogGainMinÒ»°ãÎª16£¬fAnalogGainStepÒ»°ãÎª0.125£¬ÄÇÃŽ×îÐ¡·ÅŽó±¶ÊýŸÍÊÇ16*0.125 = 2±¶
    UINT  uiExposeTimeMin;  //ÊÖ¶¯Ä£ÊœÏÂ£¬ÆØ¹âÊ±ŒäµÄ×îÐ¡Öµ£¬µ¥Î»:ÐÐ¡£žùŸÝCameraGetExposureLineTime¿ÉÒÔ»ñµÃÒ»ÐÐ¶ÔÓŠµÄÊ±Œä(Î¢Ãë),ŽÓ¶øµÃµœÕûÖ¡µÄÆØ¹âÊ±Œä
    UINT  uiExposeTimeMax;  //ÊÖ¶¯Ä£ÊœÏÂ£¬ÆØ¹âÊ±ŒäµÄ×îŽóÖµ£¬µ¥Î»:ÐÐ
} tSdkExpose;

//Ž¥·¢Ä£ÊœÃèÊö
typedef struct
{
  INT   iIndex;            //Ä£ÊœË÷ÒýºÅ
  char  acDescription[32]; //žÃÄ£ÊœµÄÃèÊöÐÅÏ¢
} tSdkTrigger;

//Ž«Êä·Ö°üŽóÐ¡ÃèÊö(Ö÷ÒªÊÇÕë¶ÔÍøÂçÏà»úÓÐÐ§)
typedef struct
{
    INT  iIndex;              //·Ö°üŽóÐ¡Ë÷ÒýºÅ
    char acDescription[32];   //¶ÔÓŠµÄÃèÊöÐÅÏ¢
    UINT iPackSize;
} tSdkPackLength;

//Ô€ÉèµÄLUT±íÃèÊö
typedef struct
{
    INT  iIndex;                //±àºÅ
    char acDescription[32];     //ÃèÊöÐÅÏ¢
} tSdkPresetLut;

//AEËã·šÃèÊö
typedef struct
{
    INT  iIndex;                //±àºÅ
    char acDescription[32];     //ÃèÊöÐÅÏ¢
} tSdkAeAlgorithm;

//RAW×ªRGBËã·šÃèÊö
typedef struct
{
    INT  iIndex;                //±àºÅ
    char acDescription[32];     //ÃèÊöÐÅÏ¢
} tSdkBayerDecodeAlgorithm;


//Ö¡ÂÊÍ³ŒÆÐÅÏ¢
typedef struct
{
  INT iTotal;           //µ±Ç°²ÉŒ¯µÄ×ÜÖ¡Êý£š°üÀšŽíÎóÖ¡£©
    INT iCapture;       //µ±Ç°²ÉŒ¯µÄÓÐÐ§Ö¡µÄÊýÁ¿
    INT iLost;          //µ±Ç°¶ªÖ¡µÄÊýÁ¿
} tSdkFrameStatistic;

//Ïà»úÊä³öµÄÍŒÏñÊýŸÝžñÊœ
typedef struct
{
  INT     iIndex;             //žñÊœÖÖÀà±àºÅ
  char    acDescription[32];  //ÃèÊöÐÅÏ¢
  UINT    iMediaType;         //¶ÔÓŠµÄÍŒÏñžñÊœ±àÂë£¬ÈçCAMERA_MEDIA_TYPE_BAYGR8£¬ÔÚ±ŸÎÄŒþÖÐÓÐ¶šÒå¡£
} tSdkMediaType;

//Ù€ÂíµÄÉè¶š·¶Î§
typedef struct
{
  INT iMin;       //×îÐ¡Öµ
  INT iMax;       //×îŽóÖµ
} tGammaRange;

//¶Ô±È¶ÈµÄÉè¶š·¶Î§
typedef struct
{
    INT iMin;   //×îÐ¡Öµ
    INT iMax;   //×îŽóÖµ
} tContrastRange;

//RGBÈýÍšµÀÊý×ÖÔöÒæµÄÉè¶š·¶Î§
typedef struct
{
    INT iRGainMin;    //ºìÉ«ÔöÒæµÄ×îÐ¡Öµ
    INT iRGainMax;    //ºìÉ«ÔöÒæµÄ×îŽóÖµ
    INT iGGainMin;    //ÂÌÉ«ÔöÒæµÄ×îÐ¡Öµ
    INT iGGainMax;    //ÂÌÉ«ÔöÒæµÄ×îŽóÖµ
    INT iBGainMin;    //À¶É«ÔöÒæµÄ×îÐ¡Öµ
    INT iBGainMax;    //À¶É«ÔöÒæµÄ×îŽóÖµ
} tRgbGainRange;

//±¥ºÍ¶ÈÉè¶šµÄ·¶Î§
typedef struct
{
    INT iMin;   //×îÐ¡Öµ
    INT iMax;   //×îŽóÖµ
} tSaturationRange;

//Èñ»¯µÄÉè¶š·¶Î§
typedef struct
{
  INT iMin;   //×îÐ¡Öµ
  INT iMax;   //×îŽóÖµ
} tSharpnessRange;

//ISPÄ£¿éµÄÊ¹ÄÜÐÅÏ¢
typedef struct
{
    BOOL bMonoSensor;       //±íÊŸžÃÐÍºÅÏà»úÊÇ·ñÎªºÚ°×Ïà»ú,Èç¹ûÊÇºÚ°×Ïà»ú£¬ÔòÑÕÉ«Ïà¹ØµÄ¹ŠÄÜ¶ŒÎÞ·šµ÷œÚ
    BOOL bWbOnce;           //±íÊŸžÃÐÍºÅÏà»úÊÇ·ñÖ§³ÖÊÖ¶¯°×Æœºâ¹ŠÄÜ
    BOOL bAutoWb;           //±íÊŸžÃÐÍºÅÏà»úÊÇ·ñÖ§³Ö×Ô¶¯°×Æœºâ¹ŠÄÜ
    BOOL bAutoExposure;     //±íÊŸžÃÐÍºÅÏà»úÊÇ·ñÖ§³Ö×Ô¶¯ÆØ¹â¹ŠÄÜ
    BOOL bManualExposure;   //±íÊŸžÃÐÍºÅÏà»úÊÇ·ñÖ§³ÖÊÖ¶¯ÆØ¹â¹ŠÄÜ
    BOOL bAntiFlick;        //±íÊŸžÃÐÍºÅÏà»úÊÇ·ñÖ§³Ö¿¹ÆµÉÁ¹ŠÄÜ
    BOOL bDeviceIsp;        //±íÊŸžÃÐÍºÅÏà»úÊÇ·ñÖ§³ÖÓ²ŒþISP¹ŠÄÜ
    BOOL bForceUseDeviceIsp;//bDeviceIspºÍbForceUseDeviceIspÍ¬Ê±ÎªTRUEÊ±£¬±íÊŸÇ¿ÖÆÖ»ÓÃÓ²ŒþISP£¬²»¿ÉÈ¡Ïû¡£
    BOOL bZoomHD;           //Ïà»úÓ²ŒþÊÇ·ñÖ§³ÖÍŒÏñËõ·ÅÊä³ö(Ö»ÄÜÊÇËõÐ¡)¡£
} tSdkIspCapacity;

/* ¶šÒåÕûºÏµÄÉè±žÃèÊöÐÅÏ¢£¬ÕâÐ©ÐÅÏ¢¿ÉÒÔÓÃÓÚ¶¯Ì¬¹¹œšUI */
typedef struct
{

  tSdkTrigger   *pTriggerDesc;          // Ž¥·¢Ä£Êœ
  INT           iTriggerDesc;           // Ž¥·¢Ä£ÊœµÄžöÊý£¬ŒŽpTriggerDescÊý×éµÄŽóÐ¡

  tSdkImageResolution   *pImageSizeDesc;// Ô€Éè·Ö±æÂÊÑ¡Ôñ
  INT                   iImageSizeDesc; // Ô€Éè·Ö±æÂÊµÄžöÊý£¬ŒŽpImageSizeDescÊý×éµÄŽóÐ¡

  tSdkColorTemperatureDes *pClrTempDesc;// Ô€ÉèÉ«ÎÂÄ£Êœ£¬ÓÃÓÚ°×Æœºâ
  INT                     iClrTempDesc;

  tSdkMediaType     *pMediaTypeDesc;    // Ïà»úÊä³öÍŒÏñžñÊœ
  INT               iMediaTypdeDesc;    // Ïà»úÊä³öÍŒÏñžñÊœµÄÖÖÀàžöÊý£¬ŒŽpMediaTypeDescÊý×éµÄŽóÐ¡¡£

  tSdkFrameSpeed    *pFrameSpeedDesc;   // ¿Éµ÷œÚÖ¡ËÙÀàÐÍ£¬¶ÔÓŠœçÃæÉÏÆÕÍš žßËÙ ºÍ³¬Œ¶ÈýÖÖËÙ¶ÈÉèÖÃ
  INT               iFrameSpeedDesc;    // ¿Éµ÷œÚÖ¡ËÙÀàÐÍµÄžöÊý£¬ŒŽpFrameSpeedDescÊý×éµÄŽóÐ¡¡£

  tSdkPackLength    *pPackLenDesc;      // Ž«Êä°ü³€¶È£¬Ò»°ãÓÃÓÚÍøÂçÉè±ž
  INT               iPackLenDesc;       // ¿É¹©Ñ¡ÔñµÄŽ«Êä·Ö°ü³€¶ÈµÄžöÊý£¬ŒŽpPackLenDescÊý×éµÄŽóÐ¡¡£

  INT           iOutputIoCounts;        // ¿É±à³ÌÊä³öIOµÄžöÊý
  INT           iInputIoCounts;         // ¿É±à³ÌÊäÈëIOµÄžöÊý

  tSdkPresetLut  *pPresetLutDesc;       // Ïà»úÔ€ÉèµÄLUT±í
  INT            iPresetLut;            // Ïà»úÔ€ÉèµÄLUT±íµÄžöÊý£¬ŒŽpPresetLutDescÊý×éµÄŽóÐ¡

  INT           iUserDataMaxLen;        // ÖžÊŸžÃÏà»úÖÐÓÃÓÚ±£ŽæÓÃ»§ÊýŸÝÇøµÄ×îŽó³€¶È¡£Îª0±íÊŸÎÞ¡£
  BOOL          bParamInDevice;         // ÖžÊŸžÃÉè±žÊÇ·ñÖ§³ÖŽÓÉè±žÖÐ¶ÁÐŽ²ÎÊý×é¡£1ÎªÖ§³Ö£¬0²»Ö§³Ö¡£

  tSdkAeAlgorithm   *pAeAlmSwDesc;      // ÈíŒþ×Ô¶¯ÆØ¹âËã·šÃèÊö
  int                iAeAlmSwDesc;      // ÈíŒþ×Ô¶¯ÆØ¹âËã·šžöÊý

  tSdkAeAlgorithm    *pAeAlmHdDesc;     // Ó²Œþ×Ô¶¯ÆØ¹âËã·šÃèÊö£¬ÎªNULL±íÊŸ²»Ö§³ÖÓ²Œþ×Ô¶¯ÆØ¹â
  int                iAeAlmHdDesc;      // Ó²Œþ×Ô¶¯ÆØ¹âËã·šžöÊý£¬Îª0±íÊŸ²»Ö§³ÖÓ²Œþ×Ô¶¯ÆØ¹â

  tSdkBayerDecodeAlgorithm   *pBayerDecAlmSwDesc; // ÈíŒþBayer×ª»»ÎªRGBÊýŸÝµÄËã·šÃèÊö
  int                        iBayerDecAlmSwDesc;  // ÈíŒþBayer×ª»»ÎªRGBÊýŸÝµÄËã·šžöÊý

  tSdkBayerDecodeAlgorithm   *pBayerDecAlmHdDesc; // Ó²ŒþBayer×ª»»ÎªRGBÊýŸÝµÄËã·šÃèÊö£¬ÎªNULL±íÊŸ²»Ö§³Ö
  int                        iBayerDecAlmHdDesc;  // Ó²ŒþBayer×ª»»ÎªRGBÊýŸÝµÄËã·šžöÊý£¬Îª0±íÊŸ²»Ö§³Ö

  /* ÍŒÏñ²ÎÊýµÄµ÷œÚ·¶Î§¶šÒå,ÓÃÓÚ¶¯Ì¬¹¹œšUI*/
  tSdkExpose            sExposeDesc;      // ÆØ¹âµÄ·¶Î§Öµ
  tSdkResolutionRange   sResolutionRange; // ·Ö±æÂÊ·¶Î§ÃèÊö
  tRgbGainRange         sRgbGainRange;    // ÍŒÏñÊý×ÖÔöÒæ·¶Î§ÃèÊö
  tSaturationRange      sSaturationRange; // ±¥ºÍ¶È·¶Î§ÃèÊö
  tGammaRange           sGammaRange;      // Ù€Âí·¶Î§ÃèÊö
  tContrastRange        sContrastRange;   // ¶Ô±È¶È·¶Î§ÃèÊö
  tSharpnessRange       sSharpnessRange;  // Èñ»¯·¶Î§ÃèÊö
  tSdkIspCapacity       sIspCapacity;     // ISPÄÜÁŠÃèÊö


} tSdkCameraCapbility;


//ÍŒÏñÖ¡Í·ÐÅÏ¢
typedef struct
{
  UINT    uiMediaType;    // ÍŒÏñžñÊœ,Image Format
  UINT    uBytes;         // ÍŒÏñÊýŸÝ×ÖœÚÊý,Total bytes
  INT     iWidth;         // ÍŒÏñµÄ¿í¶È£¬µ÷ÓÃÍŒÏñŽŠÀíº¯Êýºó£¬žÃ±äÁ¿¿ÉÄÜ±»¶¯Ì¬ÐÞžÄ£¬ÀŽÖžÊŸŽŠÀíºóµÄÍŒÏñ³ßŽç
  INT     iHeight;        // ÍŒÏñµÄžß¶È£¬µ÷ÓÃÍŒÏñŽŠÀíº¯Êýºó£¬žÃ±äÁ¿¿ÉÄÜ±»¶¯Ì¬ÐÞžÄ£¬ÀŽÖžÊŸŽŠÀíºóµÄÍŒÏñ³ßŽç
  INT     iWidthZoomSw;   // ÈíŒþËõ·ÅµÄ¿í¶È,²»ÐèÒªœøÐÐÈíŒþ²ÃŒôµÄÍŒÏñ£¬ŽË±äÁ¿ÉèÖÃÎª0.
  INT     iHeightZoomSw;  // ÈíŒþËõ·ÅµÄžß¶È,²»ÐèÒªœøÐÐÈíŒþ²ÃŒôµÄÍŒÏñ£¬ŽË±äÁ¿ÉèÖÃÎª0.
  BOOL    bIsTrigger;     // ÖžÊŸÊÇ·ñÎªŽ¥·¢Ö¡ is trigger
  UINT    uiTimeStamp;    // žÃÖ¡µÄ²ÉŒ¯Ê±Œä£¬µ¥Î»0.1ºÁÃë
  UINT    uiExpTime;      // µ±Ç°ÍŒÏñµÄÆØ¹âÖµ£¬µ¥Î»ÎªÎ¢Ãëus
  float   fAnalogGain;    // µ±Ç°ÍŒÏñµÄÄ£ÄâÔöÒæ±¶Êý
  INT     iGamma;         // žÃÖ¡ÍŒÏñµÄÙ€ÂíÉè¶šÖµ£¬œöµ±LUTÄ£ÊœÎª¶¯Ì¬²ÎÊýÉú³ÉÊ±ÓÐÐ§£¬ÆäÓàÄ£ÊœÏÂÎª-1
  INT     iContrast;      // žÃÖ¡ÍŒÏñµÄ¶Ô±È¶ÈÉè¶šÖµ£¬œöµ±LUTÄ£ÊœÎª¶¯Ì¬²ÎÊýÉú³ÉÊ±ÓÐÐ§£¬ÆäÓàÄ£ÊœÏÂÎª-1
  INT     iSaturation;    // žÃÖ¡ÍŒÏñµÄ±¥ºÍ¶ÈÉè¶šÖµ£¬¶ÔÓÚºÚ°×Ïà»úÎÞÒâÒå£¬Îª0
  float   fRgain;         // žÃÖ¡ÍŒÏñŽŠÀíµÄºìÉ«Êý×ÖÔöÒæ±¶Êý£¬¶ÔÓÚºÚ°×Ïà»úÎÞÒâÒå£¬Îª1
  float   fGgain;         // žÃÖ¡ÍŒÏñŽŠÀíµÄÂÌÉ«Êý×ÖÔöÒæ±¶Êý£¬¶ÔÓÚºÚ°×Ïà»úÎÞÒâÒå£¬Îª1
  float   fBgain;         // žÃÖ¡ÍŒÏñŽŠÀíµÄÀ¶É«Êý×ÖÔöÒæ±¶Êý£¬¶ÔÓÚºÚ°×Ïà»úÎÞÒâÒå£¬Îª1
}tSdkFrameHead;

//ÍŒÏñÖ¡ÃèÊö
typedef struct sCameraFrame
{
  tSdkFrameHead   head;     //Ö¡Í·
  BYTE *          pBuffer;  //ÊýŸÝÇø
}tSdkFrame;

//ÍŒÏñ²¶»ñµÄ»Øµ÷º¯Êý¶šÒå
typedef void (*CAMERA_SNAP_PROC)(CameraHandle hCamera, BYTE *pFrameBuffer, tSdkFrameHead* pFrameHead,PVOID pContext);

//SDKÉú³ÉµÄÏà»úÅäÖÃÒ³ÃæµÄÏûÏ¢»Øµ÷º¯Êý¶šÒå
typedef void (*CAMERA_PAGE_MSG_PROC)(CameraHandle hCamera,UINT MSG,UINT uParam,PVOID pContext);

/// @ingroup API_RECONNECT
/// \~chinese Ïà»úÁ¬œÓ×ŽÌ¬»Øµ÷
/// \param [in] hCamera Ïà»úŸä±ú
/// \param [in] MSG ÏûÏ¢£¬0: Ïà»úÁ¬œÓ¶Ï¿ª    1: Ïà»úÁ¬œÓ»ÖžŽ
/// \param [in] uParam žœŒÓÐÅÏ¢
/// \param [in] pContext ÓÃ»§ÊýŸÝ
/// \return ÎÞ
/// \note USBÏà»úuParamÈ¡Öµ£º
/// \note 		ÎŽ¶šÒå
/// \note Íø¿ÚÏà»úuParamÈ¡Öµ£º
/// \note		µ±MSG=0Ê±£ºÎŽ¶šÒå
/// \note		µ±MSG=1Ê±£º
/// \note			0£ºÉÏŽÎµôÏßÔ­Òò£¬ÍøÂçÍšÑ¶Ê§°Ü
/// \note			1£ºÉÏŽÎµôÏßÔ­Òò£¬Ïà»úµôµç
/// \~english Camera connection status callback
/// \param [in] hCamera Camera handle
/// \param [in] MSG message, 0: Camera disconnected 1: Camera connection restored
/// \param [in] uParam Additional Information
/// \param [in] pContext user data
/// \return None
/// \note USB camera uParam value:
/// \note       Undefined
/// \note network camera uParam value:
/// \note       When MSG=0: Undefined
/// \note       When MSG=1:
/// \note           0: The last dropped reason, network communication failed
/// \note           1: The last dropped reason, the camera lost power
typedef void (*CAMERA_CONNECTION_STATUS_CALLBACK)(CameraHandle hCamera,UINT MSG,UINT uParam,PVOID pContext);


//----------------------------IMAGE FORMAT DEFINE------------------------------------
//----------------------------ÍŒÏñžñÊœ¶šÒå-------------------------------------------
#define CAMERA_MEDIA_TYPE_MONO                           0x01000000
#define CAMERA_MEDIA_TYPE_RGB                            0x02000000
#define CAMERA_MEDIA_TYPE_COLOR                          0x02000000
#define CAMERA_MEDIA_TYPE_CUSTOM                         0x80000000
#define CAMERA_MEDIA_TYPE_COLOR_MASK                     0xFF000000
#define CAMERA_MEDIA_TYPE_OCCUPY1BIT                     0x00010000
#define CAMERA_MEDIA_TYPE_OCCUPY2BIT                     0x00020000
#define CAMERA_MEDIA_TYPE_OCCUPY4BIT                     0x00040000
#define CAMERA_MEDIA_TYPE_OCCUPY8BIT                     0x00080000
#define CAMERA_MEDIA_TYPE_OCCUPY10BIT                    0x000A0000
#define CAMERA_MEDIA_TYPE_OCCUPY12BIT                    0x000C0000
#define CAMERA_MEDIA_TYPE_OCCUPY16BIT                    0x00100000
#define CAMERA_MEDIA_TYPE_OCCUPY24BIT                    0x00180000
#define CAMERA_MEDIA_TYPE_OCCUPY32BIT                    0x00200000
#define CAMERA_MEDIA_TYPE_OCCUPY36BIT                    0x00240000
#define CAMERA_MEDIA_TYPE_OCCUPY48BIT                    0x00300000
#define CAMERA_MEDIA_TYPE_OCCUPY64BIT					 0x00400000

#define CAMERA_MEDIA_TYPE_EFFECTIVE_PIXEL_SIZE_MASK      0x00FF0000
#define CAMERA_MEDIA_TYPE_EFFECTIVE_PIXEL_SIZE_SHIFT     16

#define CAMERA_MEDIA_TYPE_PIXEL_SIZE(type)                 (((type) & CAMERA_MEDIA_TYPE_EFFECTIVE_PIXEL_SIZE_MASK)>>CAMERA_MEDIA_TYPE_EFFECTIVE_PIXEL_SIZE_SHIFT)

#define CAMERA_MEDIA_TYPE_ID_MASK                        0x0000FFFF
#define CAMERA_MEDIA_TYPE_COUNT                          0x46

/*mono*/
#define CAMERA_MEDIA_TYPE_MONO1P             (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY1BIT | 0x0037)
#define CAMERA_MEDIA_TYPE_MONO2P             (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY2BIT | 0x0038)
#define CAMERA_MEDIA_TYPE_MONO4P             (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY4BIT | 0x0039)
#define CAMERA_MEDIA_TYPE_MONO8              (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY8BIT | 0x0001)
#define CAMERA_MEDIA_TYPE_MONO8S             (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY8BIT | 0x0002)
#define CAMERA_MEDIA_TYPE_MONO10             (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0003)
#define CAMERA_MEDIA_TYPE_MONO10_PACKED      (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x0004)
#define CAMERA_MEDIA_TYPE_MONO12             (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0005)
#define CAMERA_MEDIA_TYPE_MONO12_PACKED      (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x0006)
#define CAMERA_MEDIA_TYPE_MONO14             (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0025)
#define CAMERA_MEDIA_TYPE_MONO16             (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0007)

/*Bayer */
#define CAMERA_MEDIA_TYPE_BAYGR8             (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY8BIT | 0x0008)
#define CAMERA_MEDIA_TYPE_BAYRG8             (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY8BIT | 0x0009)
#define CAMERA_MEDIA_TYPE_BAYGB8             (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY8BIT | 0x000A)
#define CAMERA_MEDIA_TYPE_BAYBG8             (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY8BIT | 0x000B)

#define CAMERA_MEDIA_TYPE_BAYGR10_MIPI       (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY10BIT | 0x0026)
#define CAMERA_MEDIA_TYPE_BAYRG10_MIPI       (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY10BIT | 0x0027)
#define CAMERA_MEDIA_TYPE_BAYGB10_MIPI       (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY10BIT | 0x0028)
#define CAMERA_MEDIA_TYPE_BAYBG10_MIPI       (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY10BIT | 0x0029)


#define CAMERA_MEDIA_TYPE_BAYGR10            (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x000C)
#define CAMERA_MEDIA_TYPE_BAYRG10            (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x000D)
#define CAMERA_MEDIA_TYPE_BAYGB10            (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x000E)
#define CAMERA_MEDIA_TYPE_BAYBG10            (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x000F)

#define CAMERA_MEDIA_TYPE_BAYGR12            (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0010)
#define CAMERA_MEDIA_TYPE_BAYRG12            (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0011)
#define CAMERA_MEDIA_TYPE_BAYGB12            (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0012)
#define CAMERA_MEDIA_TYPE_BAYBG12            (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0013)


#define CAMERA_MEDIA_TYPE_BAYGR10_PACKED     (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x0026)
#define CAMERA_MEDIA_TYPE_BAYRG10_PACKED     (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x0027)
#define CAMERA_MEDIA_TYPE_BAYGB10_PACKED     (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x0028)
#define CAMERA_MEDIA_TYPE_BAYBG10_PACKED     (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x0029)

#define CAMERA_MEDIA_TYPE_BAYGR12_PACKED     (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x002A)
#define CAMERA_MEDIA_TYPE_BAYRG12_PACKED     (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x002B)
#define CAMERA_MEDIA_TYPE_BAYGB12_PACKED     (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x002C)
#define CAMERA_MEDIA_TYPE_BAYBG12_PACKED     (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x002D)

#define CAMERA_MEDIA_TYPE_BAYGR16            (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x002E)
#define CAMERA_MEDIA_TYPE_BAYRG16            (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x002F)
#define CAMERA_MEDIA_TYPE_BAYGB16            (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0030)
#define CAMERA_MEDIA_TYPE_BAYBG16            (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0031)

/*RGB */
#define CAMERA_MEDIA_TYPE_RGB8               (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY24BIT | 0x0014)
#define CAMERA_MEDIA_TYPE_BGR8               (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY24BIT | 0x0015)
#define CAMERA_MEDIA_TYPE_RGBA8              (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY32BIT | 0x0016)
#define CAMERA_MEDIA_TYPE_BGRA8              (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY32BIT | 0x0017)
#define CAMERA_MEDIA_TYPE_RGB10              (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY48BIT | 0x0018)
#define CAMERA_MEDIA_TYPE_BGR10              (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY48BIT | 0x0019)
#define CAMERA_MEDIA_TYPE_RGB12              (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY48BIT | 0x001A)
#define CAMERA_MEDIA_TYPE_BGR12              (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY48BIT | 0x001B)
#define CAMERA_MEDIA_TYPE_RGB16              (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY48BIT | 0x0033)
#define CAMERA_MEDIA_TYPE_BGR16              (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY48BIT | 0x004B)
#define CAMERA_MEDIA_TYPE_RGBA16             (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY64BIT | 0x0064)
#define CAMERA_MEDIA_TYPE_BGRA16             (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY64BIT | 0x0051)
#define CAMERA_MEDIA_TYPE_RGB10V1_PACKED     (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY32BIT | 0x001C)
#define CAMERA_MEDIA_TYPE_RGB10P32           (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY32BIT | 0x001D)
#define CAMERA_MEDIA_TYPE_RGB12V1_PACKED     (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY36BIT | 0X0034)
#define CAMERA_MEDIA_TYPE_RGB565P            (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0035)
#define CAMERA_MEDIA_TYPE_BGR565P            (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0X0036)

/*YUV and YCbCr*/
#define CAMERA_MEDIA_TYPE_YUV411_8_UYYVYY    (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x001E)
#define CAMERA_MEDIA_TYPE_YUV422_8_UYVY      (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x001F)
#define CAMERA_MEDIA_TYPE_YUV422_8           (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0032)
#define CAMERA_MEDIA_TYPE_YUV8_UYV           (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY24BIT | 0x0020)
#define CAMERA_MEDIA_TYPE_YCBCR8_CBYCR       (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY24BIT | 0x003A)
//CAMERA_MEDIA_TYPE_YCBCR422_8 : YYYYCbCrCbCr
#define CAMERA_MEDIA_TYPE_YCBCR422_8             (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x003B)
#define CAMERA_MEDIA_TYPE_YCBCR422_8_CBYCRY      (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0043)
#define CAMERA_MEDIA_TYPE_YCBCR411_8_CBYYCRYY    (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x003C)
#define CAMERA_MEDIA_TYPE_YCBCR601_8_CBYCR       (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY24BIT | 0x003D)
#define CAMERA_MEDIA_TYPE_YCBCR601_422_8         (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x003E)
#define CAMERA_MEDIA_TYPE_YCBCR601_422_8_CBYCRY  (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0044)
#define CAMERA_MEDIA_TYPE_YCBCR601_411_8_CBYYCRYY    (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x003F)
#define CAMERA_MEDIA_TYPE_YCBCR709_8_CBYCR           (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY24BIT | 0x0040)
#define CAMERA_MEDIA_TYPE_YCBCR709_422_8             (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0041)
#define CAMERA_MEDIA_TYPE_YCBCR709_422_8_CBYCRY      (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY16BIT | 0x0045)
#define CAMERA_MEDIA_TYPE_YCBCR709_411_8_CBYYCRYY    (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x0042)

/*RGB Planar */
#define CAMERA_MEDIA_TYPE_RGB8_PLANAR        (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY24BIT | 0x0021)
#define CAMERA_MEDIA_TYPE_RGB10_PLANAR       (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY48BIT | 0x0022)
#define CAMERA_MEDIA_TYPE_RGB12_PLANAR       (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY48BIT | 0x0023)
#define CAMERA_MEDIA_TYPE_RGB16_PLANAR       (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY48BIT | 0x0024)



/*MindVision 12bit packed bayer*/
#define CAMERA_MEDIA_TYPE_BAYGR12_PACKED_MV     (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x0060)
#define CAMERA_MEDIA_TYPE_BAYRG12_PACKED_MV     (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x0061)
#define CAMERA_MEDIA_TYPE_BAYGB12_PACKED_MV     (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x0062)
#define CAMERA_MEDIA_TYPE_BAYBG12_PACKED_MV     (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x0063)

/*MindVision 12bit packed monochome*/
#define CAMERA_MEDIA_TYPE_MONO12_PACKED_MV     (CAMERA_MEDIA_TYPE_MONO | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x0064)
#define CAMERA_MEDIA_TYPE_YUV420P_MV			     (CAMERA_MEDIA_TYPE_COLOR | CAMERA_MEDIA_TYPE_OCCUPY12BIT | 0x0065)
#endif
