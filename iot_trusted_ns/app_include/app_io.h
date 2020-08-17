/***************************************************************************************************
*                    (c) Copyright 1992-2019 Embedded Products Research Center
*                                       All Rights Reserved
*
*\File          app_io.h
*\Description
*\Note
*\Log           2019.08.07    Ver 1.0    冯传
*               创建文件。
***************************************************************************************************/
#ifndef _APP_IO_H
#define _APP_IO_H

#include "type.h"

typedef enum
{
    IO_O_NB_STATE,
    IO_O_CSQ,
    IO_O_ADC1,
    IO_O_ADC2,
    IO_O_ADC3,
    IO_O_ADC4,
    IO_I_DIN1,
    IO_I_DIN2,
    IO_I_DIN3,
    IO_I_DIN4,
    IO_I_MODULE_TYPE,
    IO_I_WORK_MODE,
    IO_O_NB_PSM_INT,
    IO_O_DOUT1,
    IO_O_DOUT2,
    IO_O_DOUT3,
    IO_O_DOUT4,
    IO_O_NB_RST,
    IO_O_NB_PWR_ONOFF,
    IO_O_NB_PWR_KEY,
    IO_O_PWR_WARNING,
    IO_O_485_1_WARNING,
    IO_O_485_2_WARNING,
    IO_O_WORK_STAT,
    IO_O_NB_SIM,
    IO_NUM
}AppIOType;

typedef enum
{
    IO_FLASH_NONE,
    IO_FLASH_1,
    IO_FLASH_2,
    IO_FLASH_3,
    IO_FLASH_4,
    IO_FLASH_5,
    IO_FLASH_6,
    IO_FLASH_7,
    IO_FLASH_8,
    IO_FLASH_9,
    IO_FLASH_10
}AppIOFlashType;

bool AppIOInit();
bool AppIOSet(AppIOType io, u8 value, AppIOFlashType flash_type);
bool AppIOInvert(AppIOType io, AppIOFlashType flash_type);
u8 AppIOGet(AppIOType io);

#endif /*_APP_IO_H*/
