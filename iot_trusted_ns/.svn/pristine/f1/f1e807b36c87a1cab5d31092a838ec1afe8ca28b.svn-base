#ifndef _USDL_TOOLS_H
#define _USDL_TOOLS_H

#include "type.h"
#include "string.h"

#define CODEFILE ((StrRChr(__FILE__, '\\') == NULL) ? \
    ((u8*)__FILE__) : (StrRChr(__FILE__, '\\') + 1))    /*!<获取当前文件名,不含路径*/


#define CODELINE (__LINE__) /*!<获取当前代码所在行*/

#define CURDATETIME (__DATE__" "__TIME__)   /*!<当前编译日期时间*/

#define CTYPE_U     0x01    /*!<upper*/
#define CTYPE_L     0x02    /*!<lower*/
#define CTYPE_D     0x04    /*!<digit*/
#define CTYPE_C     0x08    /*!<cntrl*/
#define CTYPE_P     0x10    /*!<punct*/
#define CTYPE_S     0x20    /*!<white space (space/lf/tab)*/
#define CTYPE_X     0x40    /*!<hex digit*/
#define CTYPE_SP    0x80    /*!<hard space (0x20)*/

extern const u8 CType[];

#define IS_MASK(x)      (CType[(s32)(u8)(x)])
#define IS_ALNUM(c)     ((IS_MASK(c)&(CTYPE_U|CTYPE_L|CTYPE_D)) != 0)   /*!<判断字符变量c是否为字母或数字*/
#define IS_ALPHA(c)     ((IS_MASK(c)&(CTYPE_U|CTYPE_L)) != 0)   /*!<判断字符变量c是否为字母*/
#define IS_CNTRL(c)     ((IS_MASK(c)&(CTYPE_C)) != 0)   /*!<判断字符变量c是否为控制字符*/
#define IS_DIGIT(c)     ((IS_MASK(c)&(CTYPE_D)) != 0)   /*!<判断字符变量c是否为数字*/
#define IS_GRAPH(c)     ((IS_MASK(c)&(CTYPE_P|CTYPE_U|CTYPE_L|CTYPE_D)) != 0)
#define IS_LOWER(c)     ((IS_MASK(c)&(CTYPE_L)) != 0)   /*!<判断字符变量c是否为小写字母*/
#define IS_PRINT(c)     ((IS_MASK(c)&(CTYPE_P|CTYPE_U|CTYPE_L|CTYPE_D|CTYPE_SP)) != 0)
#define IS_PUNCT(c)     ((IS_MASK(c)&(CTYPE_P)) != 0)
#define IS_SPACE(c)     ((IS_MASK(c)&(CTYPE_S)) != 0)   /*!<判断字符变量c是否为空格*/
#define IS_UPPER(c)     ((IS_MASK(c)&(CTYPE_U)) != 0)   /*!<判断字符变量c是否为大小字母*/
#define IS_XDIGIT(c)    ((IS_MASK(c)&(CTYPE_D|CTYPE_X)) != 0)
#define IS_ASCII(c)     (((u8)(c))<=0x7f)       /*!<判断字符变量c是否为ASCII码*/
#define TO_ASCII(c)     (((u8)(c))&0x7f)        /*!<把字符变量c转换为ASCII码*/
#define TO_UPPER(c)     (IS_LOWER(c) ? ((c) - 'a' + 'A') : (c)) /*!<把字符变量c转换为大写字母*/
#define TO_LOWER(c)     (IS_UPPER(c) ? ((c) - 'A' + 'a') : (c)) /*!<把字符变量c转换为小写字母*/

extern u64 MemU64DoubleInvalid;

#define INVALID_DOUBLE  (*(double*)&MemU64DoubleInvalid)  /*!<无效double值*/
u8 BitGet(u64 value, u8 pos);

#define MinBlockSize(data_size, block_size) ((data_size + block_size - 1) / block_size * block_size)

#define Max(x, y) ((x)<(y)?(y):(x))


#define Min(x, y) ((x)<(y)?(x):(y))

#define Swap(a, b) {(a)^=(b); (b)^=(a); (a)^=(b);}

#define DoubleMem(var) (*(u64*)(&(var)))

#define DoubleSetInvalid(var) (*(u64*)(&(var)) = ~(0ULL))

#define DoubleIsNumber(value) ((value) == (value))    /*!<判断double的合法性*/

u32 GetSub(u32 value1, u32 value2);

bool InRange(u32 value, u32 begin, u32 end);

u64 BCDAdd(u64 bcd, u64 value);

u64 BCDSub(u64 bcd, u64 value);

bool BCDFix(u8* bcd);


bool BCDArrayFix(void* bcd_array, u32 len);


void BCDLeftMov(void* bcd_array, u32 len, u32 mov_num);


void BCDRightMov(void* bcd_array, u32 len, u32 mov_num);


u8 BCDLeftMovU8(u8 bcd, u32 mov_num);

u16 BCDLeftMovU16(u16 bcd, u32 mov_num);


u32 BCDLeftMovU32(u32 bcd, u32 mov_num);


u64 BCDLeftMovU64(u64 bcd, u32 mov_num);


u8 BCDRightMovU8(u8 bcd, u32 mov_num);


u16 BCDRightMovU16(u16 bcd, u32 mov_num);


u32 BCDRightMovU32(u32 bcd, u32 mov_num);


u64 BCDRightMovU64(u64 bcd, u32 mov_num);

bool WaitFlag(const void* flag, const u8 flag_width, const u32 value, u32 (*wait)(u32), const u32 timeout);

#endif /*_USDL_TOOLS_H*/
