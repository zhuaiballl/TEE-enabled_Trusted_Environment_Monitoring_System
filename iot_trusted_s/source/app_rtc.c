#include "app_rtc.h"
#include "secure_variable.h"

#define DEBUG_RTC 0
#include "fsl_debug_console.h"

bool RTC_set 		= false;
//bool rtc_alarm		= true;

void RTC_IRQHandler(void)
{
    if (RTC_GetStatusFlags(RTC) & kRTC_AlarmFlag)
    {
    	u32 currSeconds = 0;
    	//rtc_alarm = true;
    	*Rtc_Alarm  = true;
        /* Clear alarm flag */
        RTC_ClearStatusFlags(RTC, kRTC_AlarmFlag);

    	currSeconds = RTC->COUNT;
    	/* Add alarm seconds to current time */
    	currSeconds += Para_Upload_Cycle;
    	/* Set alarm time in seconds */
    	RTC->MATCH  = currSeconds;
    }

}

void App_Set_RTC(rtc_datetime_t date)
{
	RTC_StopTimer(RTC);
	/* Set RTC time to default */
	RTC_SetDatetime(RTC, &date);
	/* Enable RTC alarm interrupt */
	RTC_EnableInterrupts(RTC, kRTC_AlarmInterruptEnable);
	/* Enable at the NVIC */
	EnableIRQ(RTC_IRQn);
	/* Start the RTC time counter */
	RTC_StartTimer(RTC);

	if(!RTC_set)
	{
		App_SetAlarm_RTC(Para_Upload_Cycle);
		RTC_set = true;
	}
}


void App_SetAlarm_RTC(u8 minute)
{
	u32 currSeconds = 0;
	rtc_datetime_t 		date;

#if	DEBUG_RTC
    RTC_GetDatetime(RTC, &date);
    /* print default time */
    PRINTF("Current datetime: %04d-%02d-%02d %02d:%02d:%02d\r\n", date.year, date.month, date.day, date.hour,
           date.minute, date.second);
#endif

	currSeconds = RTC->COUNT;

	/* Add alarm seconds to current time */
	//currSeconds += minute*60;
	currSeconds += minute;
	/* Set alarm time in seconds */
	RTC->MATCH = currSeconds;

#if DEBUG_RTC
    RTC_GetAlarm(RTC, &date);
    PRINTF("Alarm will occur at: %04d-%02d-%02d %02d:%02d:%02d\r\n", date.year, date.month, date.day, date.hour, date.minute, date.second);
#endif
}

