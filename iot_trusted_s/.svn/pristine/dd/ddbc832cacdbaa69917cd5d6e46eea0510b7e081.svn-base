#include "type.h"
#include "usdl_buf.h"
#include "fsl_spi.h"

#define SPI_MAX_BUF_SIZE (20*1024)

bool AppSpiInit(void* app_spi);

typedef struct AppSpiType_st
{
    SPI_Type *   			Spi;
    u8      				SpiBuf[SPI_MAX_BUF_SIZE];
    BufType 				CycleRecvBuf;
    u8      				C;
    spi_master_handle_t 	d_spiHandle;
}AppSpiType;

extern void* AppSpiCamera;
