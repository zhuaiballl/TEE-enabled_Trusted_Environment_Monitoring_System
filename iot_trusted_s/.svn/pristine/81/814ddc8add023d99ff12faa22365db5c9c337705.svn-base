#include "app_camera.h"
//#include "app_spi.h"
#include "stdlib.h"
#include "fsl_debug_console.h"

#define IMAGE_BUF_LEN 1024*60

char STOPBUF[5] 	= {0x56,0x00,0x36,0x01,0x00};
char GETBUFLEN[5] 	= {0x56,0x00,0x34,0x01,0x00};
char readimage[16]  = {0x56,0x00,0x32,0x0C,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00};//readimage[10]~[13]是长度
char RESUME[5]		= {0x56,0x00,0x36,0x01,0x03};

static char Image_Recv_buf [IMAGE_BUF_LEN];
u32 image_summer(u32 len);

u32 app_camera_read()
{
	int timer 			= 0;
	u32 image_len 		= 0,recv_len = 0;
	u8 com_recv_buf[10]	= {0};
	u8 image_lenc[4]	= {0};
	u32 image_sum 		= 0;
	AppUartClear(AppUartCamera);
	AppUartSend(AppUartCamera,STOPBUF,5);
	while(timer < 2000000)
	{
		timer ++;
	}

	timer = 0;
	while(recv_len < 5)
	{
		recv_len += AppUartRecv(AppUartCamera,com_recv_buf, 5, true);
		timer ++;
		if(timer > 2000000)
		{
			return 0;
		}
	}
	recv_len = 0;
	timer = 0;
	if(com_recv_buf[0] != 0x76)
	{
		return 0;
	}
	//maybe if(buf == 7600360000)
	AppUartSend(AppUartCamera,GETBUFLEN,5);
	while(timer < 2000000)
	{
		timer ++;
	}
	timer = 0;
	while(recv_len < 9)
	{
		recv_len += AppUartRecv(AppUartCamera,com_recv_buf, 9, true);
		timer ++;
		if(timer > 20000)
		{
			return 0;
		}
	}
	recv_len = 0;
	timer 	 = 0;
	if(com_recv_buf[0] != 0x76)
	{
		return 0;
	}
	for(int i=0;i<2;i++)
	{
		readimage[10+i+2] 	= com_recv_buf[5+i+2];
		image_lenc[i+2] 	= com_recv_buf[5+i+2];
	}
	image_len = image_lenc[2] *256 + image_lenc[3];
	AppUartSend(AppUartCamera,readimage,16);

	timer = 0;
	//buf里首尾都各有5个字节的标志，不在image中
	while(recv_len < image_len + 10)
	{
		recv_len += AppUartRecv(AppUartCamera,Image_Recv_buf + recv_len,IMAGE_BUF_LEN - recv_len,true);
		timer ++;

		if(timer > 200000000)
		{
			return 0;
		}

	}

	AppUartSend(AppUartCamera,RESUME,5);

	/*****************************************************
	image Algorithm here
	jpg image in  Image_Recv_buf[5] - Image_Recv_buf[5+image_len-1]
	/******************************************************/
	if(!Camera_Debug)
	{
		AppUartSend(AppUartDBG,&Image_Recv_buf[5],image_len);
	}
	image_sum = image_summer(image_len);
	AppUartClear(AppUartCamera);
	return image_sum;
}

u32 image_summer(u32 len)
{
	u32 sum = 0;
	for(int i = 0;i<len;i++)
	{
		sum += Image_Recv_buf[5+i];
		//PRINTF("0x%x,",Image_Recv_buf[5+i]);
	}
	PRINTF("\r\n");
	return sum;
}

void image_print()
{

}
