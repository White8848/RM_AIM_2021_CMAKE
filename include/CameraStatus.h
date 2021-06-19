#ifndef __CAMERA_STATUS_DEF__
#define __CAMERA_STATUS_DEF__

typedef int CameraSdkStatus;


/*³£ÓÃµÄºê*/
#define SDK_SUCCESS(_FUC_)              ((_FUC_) == CAMERA_STATUS_SUCCESS)

#define SDK_UNSUCCESS(_FUC_)            ((_FUC_) != CAMERA_STATUS_SUCCESS)

#define SDK_UNSUCCESS_RETURN(_FUC_,RET) if((RET = (_FUC_)) != CAMERA_STATUS_SUCCESS)\
                                        {\
                                            return RET;\
                                        }

#define SDK_UNSUCCESS_BREAK(_FUC_)      if((_FUC_) != CAMERA_STATUS_SUCCESS)\
                                        {\
                                            break;\
                                        }


/* ³£ÓÃŽíÎó  */

#define CAMERA_STATUS_SUCCESS                    0   // ²Ù×÷³É¹Š
#define CAMERA_STATUS_FAILED                    -1   // ²Ù×÷Ê§°Ü
#define CAMERA_STATUS_INTERNAL_ERROR            -2   // ÄÚ²¿ŽíÎó
#define CAMERA_STATUS_UNKNOW                    -3   // ÎŽÖªŽíÎó
#define CAMERA_STATUS_NOT_SUPPORTED             -4   // ²»Ö§³ÖžÃ¹ŠÄÜ
#define CAMERA_STATUS_NOT_INITIALIZED           -5   // ³õÊŒ»¯ÎŽÍê³É
#define CAMERA_STATUS_PARAMETER_INVALID         -6   // ²ÎÊýÎÞÐ§
#define CAMERA_STATUS_PARAMETER_OUT_OF_BOUND    -7   // ²ÎÊýÔœœç
#define CAMERA_STATUS_UNENABLED                 -8   // ÎŽÊ¹ÄÜ
#define CAMERA_STATUS_USER_CANCEL               -9   // ÓÃ»§ÊÖ¶¯È¡ÏûÁË£¬±ÈÈçroiÃæ°åµã»÷È¡Ïû£¬·µ»Ø
#define CAMERA_STATUS_PATH_NOT_FOUND            -10  // ×¢²á±íÖÐÃ»ÓÐÕÒµœ¶ÔÓŠµÄÂ·Ÿ¶
#define CAMERA_STATUS_SIZE_DISMATCH             -11  // »ñµÃÍŒÏñÊýŸÝ³€¶ÈºÍ¶šÒåµÄ³ßŽç²»Æ¥Åä
#define CAMERA_STATUS_TIME_OUT                  -12  // ³¬Ê±ŽíÎó
#define CAMERA_STATUS_IO_ERROR                  -13  // Ó²ŒþIOŽíÎó
#define CAMERA_STATUS_COMM_ERROR                -14  // ÍšÑ¶ŽíÎó
#define CAMERA_STATUS_BUS_ERROR                 -15  // ×ÜÏßŽíÎó
#define CAMERA_STATUS_NO_DEVICE_FOUND           -16  // Ã»ÓÐ·¢ÏÖÉè±ž
#define CAMERA_STATUS_NO_LOGIC_DEVICE_FOUND     -17  // ÎŽÕÒµœÂßŒ­Éè±ž
#define CAMERA_STATUS_DEVICE_IS_OPENED          -18  // Éè±žÒÑŸ­Žò¿ª
#define CAMERA_STATUS_DEVICE_IS_CLOSED          -19  // Éè±žÒÑŸ­¹Ø±Õ
#define CAMERA_STATUS_DEVICE_VEDIO_CLOSED       -20  // Ã»ÓÐŽò¿ªÉè±žÊÓÆµ£¬µ÷ÓÃÂŒÏñÏà¹ØµÄº¯ÊýÊ±£¬Èç¹ûÏà»úÊÓÆµÃ»ÓÐŽò¿ª£¬Ôò»Ø·µ»ØžÃŽíÎó¡£
#define CAMERA_STATUS_NO_MEMORY                 -21  // Ã»ÓÐ×ã¹»ÏµÍ³ÄÚŽæ
#define CAMERA_STATUS_FILE_CREATE_FAILED        -22  // ŽŽœšÎÄŒþÊ§°Ü
#define CAMERA_STATUS_FILE_INVALID              -23  // ÎÄŒþžñÊœÎÞÐ§
#define CAMERA_STATUS_WRITE_PROTECTED           -24  // ÐŽ±£»€£¬²»¿ÉÐŽ
#define CAMERA_STATUS_GRAB_FAILED               -25  // ÊýŸÝ²ÉŒ¯Ê§°Ü
#define CAMERA_STATUS_LOST_DATA                 -26  // ÊýŸÝ¶ªÊ§£¬²»ÍêÕû
#define CAMERA_STATUS_EOF_ERROR                 -27  // ÎŽœÓÊÕµœÖ¡œáÊø·û
#define CAMERA_STATUS_BUSY                      -28  // ÕýÃŠ(ÉÏÒ»ŽÎ²Ù×÷»¹ÔÚœøÐÐÖÐ)£¬ŽËŽÎ²Ù×÷²»ÄÜœøÐÐ
#define CAMERA_STATUS_WAIT                      -29  // ÐèÒªµÈŽý(œøÐÐ²Ù×÷µÄÌõŒþ²»³ÉÁ¢)£¬¿ÉÒÔÔÙŽÎ³¢ÊÔtrf
#define CAMERA_STATUS_IN_PROCESS                -30  // ÕýÔÚœøÐÐ£¬ÒÑŸ­±»²Ù×÷¹ý
#define CAMERA_STATUS_IIC_ERROR                 -31  // IICŽ«ÊäŽíÎó
#define CAMERA_STATUS_SPI_ERROR                 -32  // SPIŽ«ÊäŽíÎó
#define CAMERA_STATUS_USB_CONTROL_ERROR         -33  // USB¿ØÖÆŽ«ÊäŽíÎó
#define CAMERA_STATUS_USB_BULK_ERROR            -34  // USB BULKŽ«ÊäŽíÎó
#define CAMERA_STATUS_SOCKET_INIT_ERROR         -35  // ÍøÂçŽ«ÊäÌ×Œþ³õÊŒ»¯Ê§°Ü
#define CAMERA_STATUS_GIGE_FILTER_INIT_ERROR    -36  // ÍøÂçÏà»úÄÚºË¹ýÂËÇý¶¯³õÊŒ»¯Ê§°Ü£¬ÇëŒì²éÊÇ·ñÕýÈ·°²×°ÁËÇý¶¯£¬»òÕßÖØÐÂ°²×°¡£
#define CAMERA_STATUS_NET_SEND_ERROR            -37  // ÍøÂçÊýŸÝ·¢ËÍŽíÎó
#define CAMERA_STATUS_DEVICE_LOST               -38  // ÓëÍøÂçÏà»úÊ§È¥Á¬œÓ£¬ÐÄÌøŒì²â³¬Ê±
#define CAMERA_STATUS_DATA_RECV_LESS            -39  // œÓÊÕµœµÄ×ÖœÚÊý±ÈÇëÇóµÄÉÙ
#define CAMERA_STATUS_FUNCTION_LOAD_FAILED      -40  // ŽÓÎÄŒþÖÐŒÓÔØ³ÌÐòÊ§°Ü
#define CAMERA_STATUS_CRITICAL_FILE_LOST        -41  // ³ÌÐòÔËÐÐËù±ØÐëµÄÎÄŒþ¶ªÊ§¡£
#define CAMERA_STATUS_SENSOR_ID_DISMATCH        -42  // ¹ÌŒþºÍ³ÌÐò²»Æ¥Åä£¬Ô­ÒòÊÇÏÂÔØÁËŽíÎóµÄ¹ÌŒþ¡£
#define CAMERA_STATUS_OUT_OF_RANGE              -43  // ²ÎÊý³¬³öÓÐÐ§·¶Î§¡£
#define CAMERA_STATUS_REGISTRY_ERROR            -44  // °²×°³ÌÐò×¢²áŽíÎó¡£ÇëÖØÐÂ°²×°³ÌÐò£¬»òÕßÔËÐÐ°²×°Ä¿ÂŒSetup/Installer.exe
#define CAMERA_STATUS_ACCESS_DENY               -45  // œûÖ¹·ÃÎÊ¡£Öž¶šÏà»úÒÑŸ­±»ÆäËû³ÌÐòÕŒÓÃÊ±£¬ÔÙÉêÇë·ÃÎÊžÃÏà»ú£¬»á·µ»ØžÃ×ŽÌ¬¡£(Ò»žöÏà»ú²»ÄÜ±»¶àžö³ÌÐòÍ¬Ê±·ÃÎÊ)
#define CAMERA_STATUS_CAMERA_NEED_RESET         -46  // ±íÊŸÏà»úÐèÒªžŽÎ»ºó²ÅÄÜÕý³£Ê¹ÓÃ£¬ŽËÊ±ÇëÈÃÏà»ú¶ÏµçÖØÆô£¬»òÕßÖØÆô²Ù×÷ÏµÍ³ºó£¬±ã¿ÉÕý³£Ê¹ÓÃ¡£
#define CAMERA_STATUS_ISP_MOUDLE_NOT_INITIALIZED -47 // ISPÄ£¿éÎŽ³õÊŒ»¯
#define CAMERA_STATUS_ISP_DATA_CRC_ERROR        -48  // ÊýŸÝÐ£ÑéŽíÎó
#define CAMERA_STATUS_MV_TEST_FAILED            -49  // ÊýŸÝ²âÊÔÊ§°Ü
#define CAMERA_STATUS_INTERNAL_ERR1             -50	 // ÄÚ²¿ŽíÎó1
#define CAMERA_STATUS_U3V_NO_CONTROL_EP			-51	 // U3V¿ØÖÆ¶ËµãÎŽÕÒµœ
#define CAMERA_STATUS_U3V_CONTROL_ERROR			-52	 // U3V¿ØÖÆÍšÑ¶ŽíÎó




//ºÍAIAÖÆ¶šµÄ±ê×ŒÏàÍ¬
/*#define CAMERA_AIA_SUCCESS                        0x0000 */
#define CAMERA_AIA_PACKET_RESEND                          0x0100 //žÃÖ¡ÐèÒªÖØŽ«
#define CAMERA_AIA_NOT_IMPLEMENTED                        0x8001 //Éè±ž²»Ö§³ÖµÄÃüÁî
#define CAMERA_AIA_INVALID_PARAMETER                      0x8002 //ÃüÁî²ÎÊý·Ç·š
#define CAMERA_AIA_INVALID_ADDRESS                        0x8003 //²»¿É·ÃÎÊµÄµØÖ·
#define CAMERA_AIA_WRITE_PROTECT                          0x8004 //·ÃÎÊµÄ¶ÔÏó²»¿ÉÐŽ
#define CAMERA_AIA_BAD_ALIGNMENT                          0x8005 //·ÃÎÊµÄµØÖ·Ã»ÓÐ°ŽÕÕÒªÇó¶ÔÆë
#define CAMERA_AIA_ACCESS_DENIED                          0x8006 //Ã»ÓÐ·ÃÎÊÈšÏÞ
#define CAMERA_AIA_BUSY                                   0x8007 //ÃüÁîÕýÔÚŽŠÀíÖÐ
#define CAMERA_AIA_DEPRECATED                             0x8008 //0x8008-0x0800B  0x800F  žÃÖžÁîÒÑŸ­·ÏÆú
#define CAMERA_AIA_PACKET_UNAVAILABLE                     0x800C //°üÎÞÐ§
#define CAMERA_AIA_DATA_OVERRUN                           0x800D //ÊýŸÝÒç³ö£¬Íš³£ÊÇÊÕµœµÄÊýŸÝ±ÈÐèÒªµÄ¶à
#define CAMERA_AIA_INVALID_HEADER                         0x800E //ÊýŸÝ°üÍ·²¿ÖÐÄ³Ð©ÇøÓòÓëÐ­Òé²»Æ¥Åä
#define CAMERA_AIA_PACKET_NOT_YET_AVAILABLE               0x8010 //ÍŒÏñ·Ö°üÊýŸÝ»¹ÎŽ×Œ±žºÃ£¬¶àÓÃÓÚŽ¥·¢Ä£Êœ£¬ÓŠÓÃ³ÌÐò·ÃÎÊ³¬Ê±
#define CAMERA_AIA_PACKET_AND_PREV_REMOVED_FROM_MEMORY    0x8011 //ÐèÒª·ÃÎÊµÄ·Ö°üÒÑŸ­²»ŽæÔÚ¡£¶àÓÃÓÚÖØŽ«Ê±ÊýŸÝÒÑŸ­²»ÔÚ»º³åÇøÖÐ
#define CAMERA_AIA_PACKET_REMOVED_FROM_MEMORY             0x8012 //CAMERA_AIA_PACKET_AND_PREV_REMOVED_FROM_MEMORY
#define CAMERA_AIA_NO_REF_TIME                            0x0813 //Ã»ÓÐ²Î¿ŒÊ±ÖÓÔŽ¡£¶àÓÃÓÚÊ±ŒäÍ¬²œµÄÃüÁîÖŽÐÐÊ±
#define CAMERA_AIA_PACKET_TEMPORARILY_UNAVAILABLE         0x0814 //ÓÉÓÚÐÅµÀŽø¿íÎÊÌâ£¬µ±Ç°·Ö°üÔÝÊ±²»¿ÉÓÃ£¬ÐèÉÔºóœøÐÐ·ÃÎÊ
#define CAMERA_AIA_OVERFLOW                               0x0815 //Éè±ž¶ËÊýŸÝÒç³ö£¬Íš³£ÊÇ¶ÓÁÐÒÑÂú
#define CAMERA_AIA_ACTION_LATE                            0x0816 //ÃüÁîÖŽÐÐÒÑŸ­³¬¹ýÓÐÐ§µÄÖž¶šÊ±Œä
#define CAMERA_AIA_ERROR                                  0x8FFF //ŽíÎó





#endif
