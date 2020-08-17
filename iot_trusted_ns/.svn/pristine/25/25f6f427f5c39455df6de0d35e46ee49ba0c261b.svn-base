/***************************************************************************************************
*                    (c) Copyright 1992-2019 Embedded Products Research Center
*                                       All Rights Reserved
*
*\File          nb_process.h
*\Description
*\Note
*\Log           2019.08.12    Ver 1.0    冯传
*               创建文件。
***************************************************************************************************/
#ifndef _NB_PROCESS_H
#define _NB_PROCESS_H

#include "type.h"
#include "app_uart.h"
#include "app_io.h"
//#include "app_adc.h"
#include "app_nbiot.h"

#define MAX_485_TASK_NUM    4

typedef struct RS485TaskParaType_st
{
    u32 Baud;
    u32 Parity;
    u8  CollectCMD[256];
    u32 CollectCMDLen;
    u8  CollectDataHexStr[512];
    u8  TimeOut;
    u8  RS485Port;
}RS485TaskParaType;

typedef struct NBRuningParaType_st
{
    u8      Version[30];        //版本号
    s8      IMEIStr[16];        //IMEI号
    u32     HeartCycle;         //心跳周期，秒
    u32     UploadCycle;        //数据上送周期，秒
    u32     CurrSEQ;            //当前的CSQ

    u32     LastSEQ;            //上次被确认的CSQ
    u32     LastCMD;            //最近一次发送的CMD
    u32     SEQAckTimeoutCount; //等待SeqAck计数器

    //485采集参数
    RS485TaskParaType RS485CollectPara[MAX_485_TASK_NUM];

    //状态信息
    float   ADCData[4];         //ADC数据
    u32     RS485Busing : 1;    //485正在采集
    u32     CSQ : 5;            //信号强度
    u32     NBModleType : 3;    //NB模块类型
    u32     OffLineMode : 1;    //离线模式
    u32     DOUT : 4;           //DO状态
    u32     DOUTOffLine : 4;    //离线模式DO状态
    u32     DINStat : 4;        //DIN状态

    //异常信息
    u32     ErrPWR : 1;         //电源异常
    u32     ErrRS4851 : 1;      //485_1异常
    u32     ErrRS4852 : 1;      //485_2异常
    u32     ErrSim : 1;         //sim卡异常
}NBRuningParaType;

extern NBRuningParaType RunningPara;

#endif /*_NB_PROCESS_H*/

