#include "app_spi.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define APP_SPI_MASTER_IRQ FLEXCOMM7_IRQn
#define APP_SPI_MASTER_CLK_SRC kCLOCK_Flexcomm7
#define APP_SPI_MASTER_CLK_FREQ CLOCK_GetFreq(kCLOCK_Flexcomm7)
#define APP_SPI_SSEL 1
#define APP_SPI_SPOL kSPI_SpolActiveAllLow
#define APP_SPI_BPS 13500000 //13.5M BPS
AppSpiType SpiCamera =
{
	.Spi = SPI7,
    .CycleRecvBuf =
    {
        .Addr = SpiCamera.SpiBuf,
        .Size = SPI_MAX_BUF_SIZE,
        .RPos = 0,
        .WPos = 0,
        .Mode = BUF_MODE_CYCLE,
        .Apply = NULL,
        .Release = NULL
    },
};


void* AppSpiCamera = &SpiCamera;

void app_spi_callback(SPI_Type *base, spi_master_handle_t *handle, status_t status, void *userData)
{
	if(userData == 0)
	{
		u32 a =  base->FIFORD;//清空数据
		base->FIFOINTENSET |= SPI_FIFOINTENSET_RXLVL_MASK;//关闭TX，打开RX
	}
	else if(userData > 0)
	{
		SpiCamera.C = handle->rxData;
		BufAddData(&SpiCamera.CycleRecvBuf, &SpiCamera.C, 1);
		handle->userData -= 1;
		if(handle->userData == 0)
		{
			base->FIFOINTENCLR = SPI_FIFOINTENCLR_RXLVL_MASK;
		}
	}
}

bool AppSpiInit(void* app_spi)
{
	AppSpiType* spi = (AppSpiType*) app_spi;
    spi_master_config_t masterConfig = {0};
	uint32_t sourceClock             = 0U;

	CLOCK_AttachClk(kFRO12M_to_FLEXCOMM7);
	RESET_PeripheralReset(kFC7_RST_SHIFT_RSTn);

	/* Init SPI master */
	/*
	 * masterConfig.enableLoopback = false;
	 * masterConfig.enableMaster = true;
	 * masterConfig.polarity = kSPI_ClockPolarityActiveHigh;
	 * masterConfig.phase = kSPI_ClockPhaseFirstEdge;
	 * masterConfig.direction = kSPI_MsbFirst;
	 * masterConfig.baudRate_Bps = 500000U;
	 */
	SPI_MasterGetDefaultConfig(&masterConfig);
	sourceClock          = APP_SPI_MASTER_CLK_FREQ;
	masterConfig.baudRate_Bps = APP_SPI_BPS;
	masterConfig.sselNum = (spi_ssel_t)APP_SPI_SSEL;
	masterConfig.sselPol = (spi_spol_t)APP_SPI_SPOL;
	//masterConfig.phase	 = kSPI_ClockPolarityActiveLow;
	sourceClock 		 = APP_SPI_MASTER_CLK_FREQ;
	SPI_MasterInit(spi->Spi, &masterConfig, sourceClock);

	SPI_MasterTransferCreateHandle(spi->Spi,&spi->d_spiHandle,app_spi_callback,spi);
	//SPI_EnableInterrupts(spi->Spi, kSPI_RxLvlIrq);
	EnableIRQ(APP_SPI_MASTER_IRQ);

	return TRUE;
}

u32 AppSpiSend(void* app_spi, u8* buf, u32 tlen, u32 rlen)
{
	AppSpiType* spi   = (AppSpiType*) app_spi;
	status_t            spi_status;

	spi_transfer_t      app_data;
	app_data.txData     = buf;
	app_data.dataSize   = tlen;

	spi->d_spiHandle.userData = rlen;
	spi_status = SPI_MasterTransferNonBlocking (spi->Spi, &spi->d_spiHandle, &app_data);

	if ((spi_status == kStatus_InvalidArgument)||(spi_status == kStatus_SPI_Busy))
	{
		//if fail,return 0;
		return 0;
	}
	return tlen;
}
