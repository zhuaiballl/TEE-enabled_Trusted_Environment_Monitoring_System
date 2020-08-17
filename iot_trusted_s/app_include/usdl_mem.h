/***************************************************************************************************
*                    (c) Copyright 1992-2009 Embedded Products Research Center
*                                       All Rights Reserved
*
*\File          usdl_mem.h
*\Description   内存操作模块，对C标准内存函数进行扩充。
*\Log           2008.06.24    Ver 1.0
*               创建文件。
***************************************************************************************************/

#ifndef _USDL_MEM_H
#define _USDL_MEM_H

#include "type.h"


#define CODEFILE ((StrRChr(__FILE__, '\\') == NULL) ? \
    ((u8*)__FILE__) : (StrRChr(__FILE__, '\\') + 1))    /*!<获取当前文件名,不含路径*/

#define CODELINE (__LINE__) /*!<获取当前代码所在行*/

#define CURDATETIME (__DATE__" "__TIME__)   /*!<当前编译日期时间*/

/***************************************************************************************************
*\Struct        DataNode
*\Description   数据节点
***************************************************************************************************/
typedef struct
{
    void*   Data;   /*!<数据指针*/
    u32     Len;    /*!<数据长度*/
}DataNode;

/***************************************************************************************************
*内存互斥
***************************************************************************************************/
/***************************************************************************************************
*\Enum          MutexType
*\Description   互斥结构定义
***************************************************************************************************/
typedef struct MutexType_st
{
    DataNode    Obj;        /*!<互斥的数据节点*/
    bool        Valid;      /*!<是否有效*/
}MutexType;

typedef void (*MemEventErrorFunc)(const u8* info, u32 info_len, const u8* filename, u32 line);  /*!<内存事件函数类型定义*/

typedef void (*MallocEventFunc)(void* addr, u32 size, const u8* filename, u32 line);  /*!<Malloc事件函数类型定义*/
typedef void (*CallocEventFunc)(void* addr, u32 size, const u8* filename, u32 line);  /*!<Free事件函数类型定义*/
typedef void (*FreeEventFunc)(void* addr, const u8* filename, u32 line);  /*!<Free事件函数类型定义*/

/***************************************************************************************************
*基于stdlib.h实现的内存操作标准函数
***************************************************************************************************/
/***************************************************************************************************
*\Function      MallocDebug
*\Description   申请内存
*\Parameter     size        要申请的大小
*\Parameter     filename    文件名
*\Parameter     line        行号
*\Return        void*       申请到的内存地址
*\Note
*\Log           2011.02.16    Ver 1.0
*               创建函数。
***************************************************************************************************/
void* MallocDebug(u32 size, const u8* filename, u32 line);

/***************************************************************************************************
*\Macro         Malloc
*\Description   申请内存
*\Parameter     size    要申请的内存大小
*\Return        void*   申请到的内存地址
*\Log           2010.05.15    Ver 1.0
***************************************************************************************************/
#define Malloc(size)    MallocDebug(size, CODEFILE, CODELINE)

/***************************************************************************************************
*\Function      CallocDebug
*\Description   按单位数目申请内存
*\Parameter     num         要申请的单位个数
*\Parameter     size        要申请单位大小
*\Parameter     filename    文件名
*\Parameter     line        行号
*\Return        void*       申请到的内存地址
*\Note          申请后的内存被清0
*\Log           2011.02.16    Ver 1.0
*               创建函数。
***************************************************************************************************/
void* CallocDebug(u32 num, u32 size, const u8* filename, u32 line);

/***************************************************************************************************
*\Macro         Calloc
*\Description   按单位数目申请内存
*\Parameter     num     单位大小
*\Parameter     size    要申请的内存大小
*\Return        void*   申请到的内存地址
*\Note          申请后的内存被清0
*\Log           2010.05.15    Ver 1.0
***************************************************************************************************/
#define Calloc(num, size)   CallocDebug(num, size, CODEFILE, CODELINE)

/***************************************************************************************************
*\Function      ReallocDebug
*\Description   重新申请内存
*\Parameter     size        要申请的大小
*\Parameter     filename    文件名
*\Parameter     line        行号
*\Return        void*       申请到的内存地址
*\Note          相当于先free原来的，再malloc再memcpy
*\Log           2011.02.16    Ver 1.0
*               创建函数。
***************************************************************************************************/
void* ReallocDebug(void* addr, u32 size, const u8* filename, u32 line);

/***************************************************************************************************
*\Macro         Realloc
*\Description   重新申请内存
*\Parameter     addr    地址
*\Parameter     size    要申请的内存大小
*\Return        void*   申请到的内存地址
*\Note          相当于先free原来的，再malloc再memcpy
*\Log           2010.05.15    Ver 1.0
***************************************************************************************************/
#define Realloc(addr, size)   ReallocDebug(addr, size, CODEFILE, CODELINE)

/***************************************************************************************************
*\Function      FreeDebug
*\Description   释放内存
*\Parameter     ptr         内存指针
*\Parameter     filename    文件名
*\Parameter     line        行号
*\Return        void
*\Note
*\Log           2011.02.16    Ver 1.0
*               创建函数。
***************************************************************************************************/
void FreeDebug(void* addr, const u8* filename, u32 line);

/***************************************************************************************************
*\Macro         Free
*\Description   内存释放
*\Parameter     addr    地址
*\Return        void
*\Log           2010.05.15    Ver 1.0
***************************************************************************************************/
#define Free(addr)   FreeDebug(addr, CODEFILE, CODELINE)

/***************************************************************************************************
*结束
***************************************************************************************************/

/***************************************************************************************************
*\Function      MemCpy
*\Description   内存拷贝。
*\Parameter     dst     目的地址
*\Parameter     src     源地址
*\Parameter     len     长度
*\Return        void*
*\Note
*\Log           2010.12.13    Ver 1.0
*               创建函数。
***************************************************************************************************/
void* MemCpy(void* dst, const void* src, u32 len);

/***************************************************************************************************
*\Function      MemMove
*\Description   内存移动。
*\Parameter     dst     目的地址
*\Parameter     src     源地址
*\Parameter     len     长度
*\Return        void*
*\Note          1)已考虑地址重叠。
*\Log           2010.12.13    Ver 1.0
*               创建函数。
***************************************************************************************************/
void* MemMove(void* dst, const void* src, u32 len);

/***************************************************************************************************
*\Function      MemCmp
*\Description   内存比较
*\Parameter     ptr1
*\Parameter     ptr2
*\Parameter     len
*\Return        s32
*\Note
*\Log           2010.12.13    Ver 1.0
*               创建函数。
***************************************************************************************************/
s32 MemCmp(const void* ptr1, const void* ptr2, u32 len);

/***************************************************************************************************
*\Macro         MemSame
*\Description   比较两块缓冲区的数据是否相同。
*\Parameter     ptr1    第一块缓冲区指针
*\Parameter     ptr2    第二块缓冲区指针。
*\Parameter     len     缓冲区长度。
*\Return        void
*\Log           2012.05.29    Ver 1.0    高峰
***************************************************************************************************/
#define MemSame(ptr1, ptr2, len) ((MemCmp(ptr1, ptr2, len) == 0)?TRUE:FALSE)

/***************************************************************************************************
*\Function      MemSet
*\Description   内存赋值。
*\Parameter     ptr
*\Parameter     value
*\Parameter     len
*\Return        void*
*\Note
*\Log           2010.12.13    Ver 1.0
*               创建函数。
***************************************************************************************************/
void* MemSet(void* ptr, u8 value, u32 len);

/***************************************************************************************************
*\Function      MemZero
*\Description   对某块内存区域全部清零
*\Parameter     src 指向内存区域的指针。
*\Parameter     len 希望清零的内存区域的长度，单位为字节。
*\Return        void
*\Note          Optimized C memzero for the ARM。
*\Log           2011.10.31    Ver 1.0    高峰
*               创建函数。
***************************************************************************************************/
void MemZero(void* src, u32 len);

/***************************************************************************************************
*\Function      MemChr
*\Description   在内存中查找字符ch。
*\Parameter     ptr
*\Parameter     ch
*\Parameter     len
*\Return        void*
*\Note
*\Log           2010.12.13    Ver 1.0
*               创建函数。
***************************************************************************************************/
void* MemChr(const void* ptr, u8 ch, u32 len);

/***************************************************************************************************
*\Function      MemAdd
*\Description   ptr指向的内存区域中的len个字节加value
*\Parameter     ptr     指向内存区域的指针
*\Parameter     value   加和值
*\Parameter     length  内存区域的长度
*\Return        void
*\Log           2008.06.24    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemAdd(u8* ptr, const u8 value, u32 length);

/***************************************************************************************************
*\Function      MemSub
*\Description   内存区域src中len个字节减value
*\Parameter     ptr     指向内存区域的指针
*\Parameter     value   加和值
*\Parameter     length  内存区域的长度
*\Return        void
*\Log           2008.03.05    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemSub(u8* ptr, const u8 value, u32 length);

/***************************************************************************************************
*\Function      MemAnd
*\Description   ptr指向的内存区域的length个字节分别与value相与。
*\Parameter     ptr     指向内存区域的指针
*\Parameter     value   1字节的数值
*\Parameter     length  内存区域的长度
*\Return        void
*\Log           2008.06.24    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemAnd(u8* ptr, const u8 value, u32 length);

/***************************************************************************************************
*\Function      MemNot
*\Description   ptr指向的内存区域的length个字节取反。
*\Parameter     ptr     指向内存区域的指针
*\Parameter     length  内存区域的长度
*\Return        void
*\Log           2009.10.12    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemNot(u8* ptr, const u32 length);

/***************************************************************************************************
*\Function      MemBitNot
*\Description   ptr指向的内存区域的length个字节按位取反。
*\Parameter     ptr     指向内存区域的指针
*\Parameter     length  内存区域的长度
*\Return        void
*\Log           2009.10.12    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemBitNot(u8* ptr, const u32 length);

/***************************************************************************************************
*\Function      MemOr
*\Description   ptr指向的内存区域的length个字节分别与value相或。
*\Parameter     ptr     指向内存区域的指针
*\Parameter     value   1字节的数值
*\Parameter     length  内存区域的长度
*\Return        void
*\Log           2008.06.24    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemOr(u8* ptr, const u8 value, const u32 length);

/***************************************************************************************************
*\Function      MemXor
*\Description   ptr指向的内存区域的length个字节分别与value相异或。
*\Parameter     ptr     指向内存区域的指针
*\Parameter     value   1字节的数值
*\Parameter     length  内存区域的长度
*\Return        void
*\Log           2009.10.12    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemXor(u8* ptr, const u8 value, const u32 length);

/***************************************************************************************************
*\Function      MemSum
*\Description   返回内存区域ptr中length个字节的和
*\Parameter     ptr     指向内存区域的指针
*\Parameter     length  内存区域的长度
*\Return        u32
*\Log           2008.03.21    Ver 1.0
*               创建函数。
***************************************************************************************************/
u32 MemSum(const u8* ptr, const u32 length);

/***************************************************************************************************
*\Function      MemSumU8
*\Description   将ptr所指向的长度为length的缓冲区中的每一个字节相加，且不考虑进位。
*\Parameter     ptr     缓冲区指针。
*\Parameter     length  缓冲区长度。
*\Return        u8      校验和结果。
*\Log           2012.04.27    Ver 1.0    高峰
*               创建函数。
***************************************************************************************************/
u8 MemSumU8(u8* ptr, u32 length);

/***************************************************************************************************
*\Function      MemAllAnd
*\Description   返回内存区域ptr中length个字节的And
*\Parameter     ptr     指向内存区域的指针
*\Parameter     length  内存区域的长度
*\Return        u32
*\Log           2009.10.12    Ver 1.0
*               创建函数。
***************************************************************************************************/
u32 MemAllAnd(const u8* ptr, const u32 length);

/***************************************************************************************************
*\Function      MemAllOr
*\Description   返回内存区域ptr中length个字节的Or
*\Parameter     ptr     指向内存区域的指针
*\Parameter     length  内存区域的长度
*\Return        u32
*\Log           2009.10.12    Ver 1.0
*               创建函数。
***************************************************************************************************/
u32 MemAllOr(const u8* ptr, const u32 length);

/***************************************************************************************************
*\Function      MemAllXor
*\Description   返回内存区域ptr中length个字节的Xor
*\Parameter     ptr     指向内存区域的指针
*\Parameter     length  内存区域的长度
*\Return        u32
*\Log           2009.10.12    Ver 1.0
*               创建函数。
***************************************************************************************************/
u32 MemAllXor(const u8* ptr, const u32 length);

/***************************************************************************************************
*\Function      MemReverse
*\Description   ptr指向的内存区域中的length个字节逆序
*\Parameter     ptr     指向内存区域的指针
*\Parameter     length  内存区域的长度
*\Return        void
*\Log           2008.06.24    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemReverse(void* ptr, const u32 length);

/***************************************************************************************************
*\Function      MemReverseCpy
*\Description   内存区域src中len个字节逆序拷贝
*\Parameter     dst     目的地址
*\Parameter     src     源地址
*\Parameter     len     长度
*\Return        void
*\Log           2008.06.24    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemReverseCpy(u8* dst, const u8* src, u32 len);

/***************************************************************************************************
*\Function      MemLineToCycle
*\Description   内存区域src中len个字节环形拷贝到dst+start_pos起始的内存中。
*\Parameter     dst             环形缓冲区
*\Parameter     dst_size        环形缓冲区长度
*\Parameter     start_offset    环形缓冲区写入起始偏移
*\Parameter     src             数据来源内存区域
*\Parameter     len             拷贝长度
*\Return        u8*             环形写入结束时的指针（写指针）
*\Log           2008.08.04    Ver 1.0
*               创建函数。
*\Log           2009.07.30    Ver 1.1
*               修改当start_offset + len等于dst_size时dst + start_offset + len越界BUG。
***************************************************************************************************/
u8* MemLineToCycle(u8* dst, const u32 dst_size, u32 start_offset, u8* src, u32 len);

/***************************************************************************************************
*\Function      MemCycleToLine
*\Description   环形内存区域src中start_pos到end_pos的数据拷贝到dst起始的条形缓冲区中。
*\Parameter     dst         条形缓冲区
*\Parameter     src         环形缓冲区
*\Parameter     start_pos   环形缓冲区起始偏移
*\Parameter     end_pos     环形缓冲区终止偏移
*\Parameter     src_size    环形缓冲区长度
*\Return        u32         条形缓冲区实际写入长度
*\Note          1)函数不考虑目的缓冲区宽度。
*\Note          2)若需要保护可以使用MemCycleSubToLine。
*\Log           2008.08.04    Ver 1.0
*               创建函数。
***************************************************************************************************/
u32 MemCycleToLine(u8* dst, const u8* src, const u32 start_pos, const u32 end_pos, const u32 src_size);

/***************************************************************************************************
*\Function      MemCycleSubToLine
*\Description   环形内存区域src中start_pos到end_pos的前len个数据拷贝到dst起始的条形缓冲区中。
*\Parameter     dst         条形缓冲区
*\Parameter     src         环形缓冲区
*\Parameter     start_pos   环形缓冲区起始偏移
*\Parameter     end_pos     环形缓冲区终止偏移
*\Parameter     src_size    环形缓冲区长度
*\Parameter     request_len 请求长度，若[请求长度]大于[环形缓冲区数据长度]则只拷贝环形缓冲区数据。
*\Return        u32         条形缓冲区实际写入长度，小于等于request_len。
*\Note          1)函数不考虑目的缓冲区宽度，若需保护见3)。
*\Note          2)适用于定期从环形缓冲区取部分数据的操作。
*\Note          3)参数len可以填写dst_size用于目的缓冲区保护。
*\Log           2009.08.21    Ver 1.0
*               创建函数。
*\Log           2009.11.13    Ver 1.1
*               修改回写拷贝的位置错误问题。
***************************************************************************************************/
u32 MemCycleSubToLine(u8* dst, const u8* src, const u32 start_pos, const u32 end_pos,
                      const u32 src_size, const u32 request_len);

/***************************************************************************************************
*\Function      MemMatch
*\Description   使用模式内存区域来匹配目标内存区域的任意前缀, 并将通配符所代表的内存区域放
*               入结果集中。
*\Parameter     pat         指向模式内存区域的指针
*\Parameter     pat_len     模式内存区域的长度
*\Parameter     dst         指向目标内存区域的指针
*\Parameter     dst_len     目标内存区域的长度
*\Parameter     wildcard    代表通配符的指定ASCII字符
*\Parameter     result[]    Result结构数组, 存放通配符所通配的内容
*\Return        bool
*                           - TRUE    匹配成功
*                           - FALSE   匹配失败
*\Note          1) 模式内存区域只包含表示0个或任意多个字节的指定通配符。
*\Note          2) 结果集大小 >= 通配符数 + 2, 否则会发生溢出。
*\Note          3) 结果集第0项存储所匹配的全部目标内存区域, 然后依次保存通配符所代表的内存块。
*\Note          4) 参考自 Wildcard matching algorithms    by Alessandro Cantatore
*\Log           2008.08.06    Ver 1.0    gaofeng
*               创建函数。
***************************************************************************************************/
bool MemMatch(u8* pat, const u32 pat_len, u8* dst, const u32 dst_len, const u8 wildcard, DataNode result[]);

/***************************************************************************************************
*\Function      MemMem
*\Description   returns the location of the first occurence of data pattern b2 of size len2 in
                memory block b1 of size len1 or NULL if none is found.
*\Parameter     b1      data pattern
*\Parameter     len1    data pattern length
*\Parameter     b2      memory block
*\Parameter     len2    memory block length
*\Return        void*   Location of the first occurence or NULL if none if found.
*\Note          From: www.it.freebsd.org/pub/Unix/NetBSD/misc/wulf/memmem.c
*\Log           2010.05.15    Ver 1.0    高峰
*               创建函数。
***************************************************************************************************/
u8* MemMem(u8* b1, const u32 len1, u8* b2, const u32 len2);

/***************************************************************************************************
*\Function      MemBCDCheck
*\Description   检查内存区域src中len个字节是否均为BCD码。
*\Parameter     src
*\Parameter     head_len
*\Return        bool
*\Log           2008.12.02    Ver 1.0
*               创建函数。
***************************************************************************************************/
bool MemBCDCheck(const u8* src, const u32 head_len);

/***************************************************************************************************
*\Function      MemShiftR
*\Description   将内存区域src中src_len个字节循环右移shift_len个字节。
*\Parameter     src         内存地址
*\Parameter     src_len     数组长度
*\Parameter     shift_len   位移长度
*\Return        void
*\Log           2008.12.11    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemShiftR(u8* src, const u32 src_len, u32 shift_len);

/***************************************************************************************************
*\Function      MemAllSameValue
*\Description   测试内存区域src中len个字节是否全部等于value
*\Parameter     src         内存地址
*\Parameter     len         数据长度
*\Parameter     value       值
*\Return        bool        是否全部等于value
*\Log           2009.03.03    Ver 1.0
*               创建函数。
***************************************************************************************************/
bool MemAllSameValue(const u8* src, u16 len, const u8 value);

/***************************************************************************************************
*\Function      MemAllSame
*\Description   测试内存区域src中len个字节是否全部相等
*\Parameter     src     内存地址
*\Parameter     len     数据长度
*\Return        bool    是否全部相等
*\Note
*\Log           2009.03.03    Ver 1.0
*               创建函数。
***************************************************************************************************/
bool MemAllSame(u8* src, u32 len);

/***************************************************************************************************
*\Function      MemAddMem
*\Description   内存相加
*\Parameter     dst     目的地址
*\Parameter     src1    内存地址1
*\Parameter     src2    内存地址2
*\Parameter     len     长度
*\Return        void
*\Note          1)溢出不进位。
*\Log           2010.04.09    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemAddMem(u8* dst, u8* src1, u8* src2, u32 len);

/***************************************************************************************************
*\Function      MemSubMem
*\Description   内存相减
*\Parameter     dst     目的地址
*\Parameter     src1    内存地址1
*\Parameter     src2    内存地址2
*\Parameter     len     长度
*\Return        void
*\Note          1)溢出不进位。
*\Log           2010.04.09    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemSubMem(u8* dst, u8* src1, u8* src2, u32 len);

/***************************************************************************************************
*\Function      MemAndMem
*\Description   内存相与
*\Parameter     dst     目的地址
*\Parameter     src1    内存地址1
*\Parameter     src2    内存地址2
*\Parameter     len     长度
*\Return        void
*\Note          1)溢出不进位。
*\Log           2010.04.09    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemAndMem(u8* dst, u8* src1, u8* src2, u32 len);

/***************************************************************************************************
*\Function      MemAndMem
*\Description   内存或
*\Parameter     dst     目的地址
*\Parameter     src1    内存地址1
*\Parameter     src2    内存地址2
*\Parameter     len     长度
*\Return        void
*\Note          1)溢出不进位。
*\Log           2010.04.09    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemOrMem(u8* dst, u8* src1, u8* src2, u32 len);

/***************************************************************************************************
*\Function      MemAndMem
*\Description   内存异或
*\Parameter     dst     目的地址
*\Parameter     src1    内存地址1
*\Parameter     src2    内存地址2
*\Parameter     len     长度
*\Return        void
*\Note          1)溢出不进位。
*\Log           2010.04.09    Ver 1.0
*               创建函数。
***************************************************************************************************/
void MemXorMem(u8* dst, u8* src1, u8* src2, u32 len);

/***************************************************************************************************
*\Function      MemOverlapCheck
*\Description   检查两个数据节点是否有重合。
*\Parameter     a   第一个数据节点
*\Parameter     b   第二个数据节点
*\Return        DataNode    重合部分的数据节点，若不重合则返回{NULL, 0}。
*\Log           2011.11.24    Ver 1.0    骆照松
*               创建函数。
***************************************************************************************************/
DataNode MemOverlapCheck(DataNode a, DataNode b);

/***************************************************************************************************
*内存互斥
***************************************************************************************************/

/***************************************************************************************************
*\Function      MutexApply
*\Description   内存区域互斥请求
*\Parameter     addr        互斥区域地址
*\Parameter     len         互斥区域长度
*\Parameter     func        互斥处理函数
*\Parameter     func_para   互斥处理函数参数
*\Parameter     timeout     互斥等待重试次数(0:无超时阻塞)
*\Return        bool        是否请求成功
*\Note          1)发现互斥后调用func(func_para)
*\Note          2)循环调用1)timeout次
*\Log           2009.12.12    Ver 1.0
*               创建函数。
***************************************************************************************************/
bool MutexApply(void* addr, u32 len, u32 (*func)(u32), u32 func_para, u32 timeout);

/***************************************************************************************************
*\Function      MutexRelease
*\Description   互斥释放
*\Parameter     addr    释放地址
*\Return        bool    是否存在互斥
*\Log           2009.12.12    Ver 1.0
*               创建函数。
***************************************************************************************************/
bool MutexRelease(void* addr);

#endif /*_USDL_MEM_H*/

