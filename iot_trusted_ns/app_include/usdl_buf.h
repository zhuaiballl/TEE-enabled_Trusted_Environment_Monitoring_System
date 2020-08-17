#ifndef _USDL_BUF_H
#define _USDL_BUF_H

#include "type.h"

typedef enum
{
    BUF_MODE_CYCLE,     /*!<环形*/
    BUF_MODE_LINE,      /*!<条形*/
    BUF_MODE_NONE       /*!<无类型*/
}BufModeType;

typedef bool (*BufMutexFunc)(void* buf);/*!<缓冲区互斥函数定义*/

typedef struct BufType_st
{
    u8*             Addr;   /*!<缓冲区地址*/
    u32             Size;   /*!<缓冲区大小*/
    u32             RPos;   /*!<读偏移*/
    u32             WPos;   /*!<写偏移*/
    BufModeType     Mode;   /*!<存储模式*/
    BufMutexFunc    Apply;  /*!<互斥申请函数*/
    BufMutexFunc    Release;/*!<互斥释放函数*/
}BufType;


BufType BufInit(u8* addr, u32 size, BufModeType mode, BufMutexFunc apply, BufMutexFunc release);

u32 BufAddData(BufType* buf, u8* src, u32 len);

u32 BufGetData(BufType* buf, u8* dst, u32 start, u32 len);

u32 BufMovData(BufType* buf, u8* dst, u32 start, u32 len);

u32 BufDelHeadData(BufType* buf, u32 len);

u32 BufDelTailData(BufType* buf, u32 len);

u32 BufClearData(BufType* buf);

u32 BufGetDataLen(BufType* buf);

u32 BufGetLeftLen(BufType* buf);

bool BufFix(BufType* buf);
bool BufSetRPos(BufType* buf, u32 value);

bool BufSetWPos(BufType* buf, u32 value);
#endif /*_USDL_BUF_H*/

