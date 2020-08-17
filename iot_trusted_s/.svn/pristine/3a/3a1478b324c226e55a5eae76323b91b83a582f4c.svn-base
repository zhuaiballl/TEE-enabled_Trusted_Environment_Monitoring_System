#ifndef _APP_GPS_H
#define _APP_GPS_H

#include "type.h"
#include "app_uart.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "fsl_rtc.h"
/*
struct app_time
{
	u8 year;
	u8 month;
	u8 day;
	u8 hour;
	u8 minute;
	u8 second;
};
*/
struct app_locate
{
	char  WE;
	float longitude;
	char  SN;
	float latitude;
};
typedef struct app_GPS
{
	//struct app_time 	time;
	rtc_datetime_t		time;
	struct app_locate   locate;
}app_GPS;

extern app_GPS d_GPS;
bool app_recv_GPS();
bool app_GPS_recv();
u8* time_to_str(rtc_datetime_t time);
#endif
