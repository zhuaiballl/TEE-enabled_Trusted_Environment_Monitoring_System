#include "app_4G.h"

#define FGMAX_BUF_SIZE 	(1024*2)
static 	u8  FG_SendBuf[FGMAX_BUF_SIZE];
static 	u32 FG_SendBufLen = 0;
static 	u8  FG_RecvBuf[FGMAX_BUF_SIZE];
void App_4GInit()
{
	if(*Rtc_Alarm)
	{
		app_GPS_recv_s();
		upload_construct(FG_SendBuf , &FG_SendBufLen);
		if(!FG_SendBufLen)
		{
			AppUartSend(AppUart4G,FG_SendBuf,FG_SendBufLen);
			SDK_DelayAtLeastUs(3000000);
			AppUartRecv(AppUart4G, FG_RecvBuf, FGMAX_BUF_SIZE, true);
			SDK_DelayAtLeastUs(100000);
			download_construct(FG_RecvBuf);
		}
		*Rtc_Alarm = false;
	}
}

