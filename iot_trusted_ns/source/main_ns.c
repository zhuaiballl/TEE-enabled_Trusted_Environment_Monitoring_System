/*
 * Copyright 2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "veneer_table.h"
#include "pin_mux.h"
#include "board.h"
#include "clock_config.h"

#include "app_nbiot.h"
#include "app_uart.h"
#include "secure_variable.h"
#include "app_4G.h"
#define AppUart4G	AppUartNB
/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define PRINTF_NSE DbgConsole_Printf_NSE

#define USE_NB_IOT 	0
//#define USE_4G 		1
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

void SystemInit (void)
{
}
/*!
 * @brief Main function
 */

int main(void)
{

    PRINTF_NSE("Welcome in normal world!\r\n");
    if(USE_NB_IOT)
    {
    	AppUartCreatHandle(AppUartNB);
		while(1)
		{
			AppNBIOTInit();
		}
    }
    else
    {
    	AppUartCreatHandle(AppUart4G);
    	while(1)
		{
    		App_4GInit();
		}
    }
}
