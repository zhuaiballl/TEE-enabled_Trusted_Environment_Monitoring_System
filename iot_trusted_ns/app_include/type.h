#ifndef _TYPE_H
#define _TYPE_H
#include "stdint.h"
/***************************************************************************************************
*类型
***************************************************************************************************/

typedef unsigned long long          u64;    /*!<u64*/
typedef unsigned int                u32;    /*!<u32*/
typedef unsigned short              u16;    /*!<u16*/
typedef unsigned char               u8;     /*!<u8*/

typedef signed long long            s64;    /*!<s64*/
typedef signed int                  s32;    /*!<s32*/
typedef signed short                s16;    /*!<s16*/
typedef signed char                 s8;     /*!<s8*/

typedef volatile unsigned int       vu32;   /*!<vu32*/
typedef volatile unsigned short     vu16;   /*!<vu16*/
typedef volatile unsigned char      vu8;    /*!<vu8*/

typedef volatile signed int         vs32;   /*!<vs32*/
typedef volatile signed short       vs16;   /*!<vs16*/
typedef volatile signed char        vs8;    /*!<vs8*/

#ifdef  CPU_WIDE_64
typedef u64 uCpu;
#else
typedef u32 uCpu;
#endif


#ifdef TRUE
#undef TRUE
#endif
#ifdef FALSE
#undef FALSE
#endif

/***************************************************************************************************
*\Enum          bool
*\Description   bool类型的定义
***************************************************************************************************/

//typedef enum
//{
//    FALSE = 0,      /*!<FALSE，假*/
//    /*TRUE = !FALSE   /*!<TRUE，真*/
///*}bool;

#include "stdbool.h"

#define true  1
#define false 0
#define TRUE  1
#define FALSE 0
#ifdef NULL
#undef NULL
#endif

#define NULL 0  /*!<NULL的定义*/

/***************************************************************************************************
*值
***************************************************************************************************/

#define S8_MIN  (-127 - 1)  /*!<s8最小值定义*/
#define S8_MAX  127         /*!<s8最大值定义*/
#define U8_MAX  0xFF        /*!<u8最大值定义*/
#define S16_MIN (-32768)    /*!<s16最小值定义*/
#define S16_MAX 32767       /*!<s16最大值定义*/
#define U16_MAX 0xFFFF      /*!<u16最大值定义*/
#define S32_MIN (-2147483647L - 1)              /*!<s32最小值定义*/
#define S32_MAX 2147483647L                     /*!<s32最大值定义*/
#define U32_MAX 0xFFFFFFFF                      /*!<u32最大值定义*/
#define S64_MIN (-9223372036854775807LL - 1)    /*!<s64最小值定义*/
#define S64_MAX 9223372036854775807LL           /*!<s64最大值定义*/
#define U64_MAX 0xFFFFFFFFFFFFFFFF              /*!<u64最大值定义*/

/***************************************************************************************************
*程序结构
***************************************************************************************************/
#define DEAD_LOOP while(1)      /*!<while死循环定义*/

/*!<函数单次运行标志*/
#define ONCE_RUN(name, ret) {static bool name##_once_run = FALSE;\
    if (name##_once_run == TRUE) {return ret;} name##_once_run = TRUE;}

#define VOID_RET    /*!<空return*/

/***************************************************************************************************
*变参
***************************************************************************************************/
#include <stdarg.h>

typedef va_list VAListType;     /*!<变参类型定义*/

#define VA_START(ap, v) va_start(ap, v)  /*!<获取变参的起始参数地址*/


#define VA_ARG(ap, t)   va_arg(ap, t)    /*!<获取参数地址*/

#define VA_END(ap)      va_end(ap)       /*!<清空变参的参数地址*/

/***************************************************************************************************
*工具
***************************************************************************************************/
#ifdef offsetof
#undef offsetof
#endif
//#define offsetof(s, m)      ((uCpu)&(((s*)0)->m))   /*!<获取结构类型中某成员的偏移*/
#define offsetofvar(s, m)   ((uCpu)(&(s).(m) - &(s)))     /*!<获取结构体变量中某成员的偏移*/
#define sizeofmember(s, m)  (sizeof((s*)0)->m)           /*!<获取结构体中某成员的宽度*/
#define countof(a)          (sizeof(a) / sizeof(a[0]))   /*!<获取数组的元素个数*/
#define numberof(a, p)      ((((uCpu)p) - ((uCpu)&(a[0]))) / sizeof(a[0])) /*!<获取当前元素在数组中的索引位置*/


/***************************************************************************************************
*宏
***************************************************************************************************/
#define ONE_KILO    (1024UL)                /*!<1K的定义*/
#define ONE_MEGA    (ONE_KILO * 1024)       /*!<1M的定义*/
#define ONE_GIGA    (ONE_MEGA * 1024)       /*!<1G的定义*/
#define ONE_TERA    (ONE_GIGA * 1024)       /*!<1T的定义*/
#define ONE_PETA    (ONE_TERA * 1024)       /*!<1P的定义*/
#define ONE_EXA     (ONE_PETA * 1024)       /*!<1E的定义*/
#define ONE_ZETA    (ONE_EXA * 1024)        /*!<1Z的定义*/
#define ONE_YOTTA   (ONE_ZETA * 1024)       /*!<1Y的定义*/
#define ONE_NONA    (ONE_YOTTA * 1024)      /*!<1N的定义*/
#define ONE_DOGGA   (ONE_DOGGA * 1024)      /*!<1D的定义*/

/***************************************************************************************************
*数组批量相同值宏
***************************************************************************************************/
#define V2(V)       (V),        (V)         /*!<2个值的定义*/
#define V4(V)       V2(V),      V2(V)       /*!<4个值的定义*/
#define V8(V)       V4(V),      V4(V)       /*!<8个值的定义*/
#define V16(V)      V8(V),      V8(V)       /*!<16个值的定义*/
#define V32(V)      V16(V),     V16(V)      /*!<32个值的定义*/
#define V64(V)      V32(V),     V32(V)      /*!<64个值的定义*/
#define V128(V)     V64(V),     V64(V)      /*!<128个值的定义*/
#define V256(V)     V128(V),    V128(V)     /*!<256个值的的定义*/
#define V512(V)     V256(V),    V256(V)     /*!<512个值的的定义*/
#define V1024(V)    V512(V),    V512(V)     /*!<1024个值的的定义*/
#define V2048(V)    V1024(V),   V1024(V)    /*!<2048个值的的定义*/
#define V4096(V)    V2048(V),   V2048(V)    /*!<4096个值的的定义*/
#define V8192(V)    V4096(V),   V4096(V)    /*!<8192个值的的定义*/
#define V16384(V)   V8192(V),   V8192(V)    /*!<16384个值的的定义*/
#define V32768(V)   V16384(V),  V16384(V)   /*!<32768个值的的定义*/
#define V65536(V)   V32768(V),  V32768(V)   /*!<65536个值的的定义*/
#define V131072(V)  V65536(V),  V65536(V)   /*!<131072个值的的定义*/
#define V262144(V)  V131072(V), V131072(V)  /*!<262144个值的的定义*/
#define V524288(V)  V262144(V), V262144(V)  /*!<524288个值的的定义*/
#define V1048576(V) V524288(V), V524288(V)  /*!<1048576个值的的定义*/



/*STD_RGB*/

/*
typedef union RGB_st
{
        u32 Value;
        struct
        {
            u8 Alpha;
            u8 Red;
            u8 Green;
            u8 Blue;
        };
}ColorRGB;
*/

/***************************************************************************************************
*\Enum          RGBMask
*\Description   颜色掩码的定义
***************************************************************************************************/
typedef enum
{
    ALPHA_MASK  = 0x00000000,   /*!<ALPHA_MASK*/
    RED_MASK    = 0x00FF0000,   /*!<红色掩码*/
    GREEN_MASK  = 0x0000FF00,   /*!<绿色掩码*/
    BLUE_MASK   = 0x000000FF    /*!<蓝色掩码*/
}RGBMask;

/*颜色的定义*/
/***************************************************************************************************
*\Enum          ColorRGB
*\Description   颜色的定义
***************************************************************************************************/
typedef enum
{
    RGB_ALICEBLUE               = 0x00F0F8FF,   /*!<RGB_ALICEBLUE*/
    RGB_ANTIQUEWHITE            = 0x00FAEBD7,   /*!<RGB_ANTIQUEWHITE*/
    RGB_AQUA                    = 0x0000FFFF,   /*!<RGB_AQUA*/
    RGB_AQUAMARINE              = 0x007FFFD4,   /*!<RGB_AQUAMARINE*/
    RGB_AZURE                   = 0x00F0FFFF,   /*!<RGB_AZURE*/
    RGB_BEIGE                   = 0x00F5F5DC,   /*!<RGB_BEIGE*/
    RGB_BISQUE                  = 0x00FFE4C4,   /*!<RGB_BISQUE*/
    RGB_BLACK                   = 0x00000000,   /*!<黑色*/
    RGB_BLANCHEDALMOND          = 0x00FFEBCD,   /*!<RGB_BLANCHEDALMOND*/
    RGB_BLUE                    = 0x000000FF,   /*!<蓝色*/
    RGB_BLUEVIOLET              = 0x008A2BE2,   /*!<RGB_BLUEVIOLET*/
    RGB_BROWN                   = 0x00A52A2A,   /*!<棕色*/
    RGB_BURLYWOOD               = 0x00DEB887,   /*!<RGB_BURLYWOOD*/
    RGB_CADETBLUE               = 0x005F9EA0,   /*!<RGB_CADETBLUE*/
    RGB_CHARTREUSE              = 0x007FFF00,   /*!<RGB_CHARTREUSE*/
    RGB_CHOCOLATE               = 0x00D2691E,   /*!<RGB_CHOCOLATE*/
    RGB_CORAL                   = 0x00FF7F50,   /*!<RGB_CORAL*/
    RGB_CORNFLOWERBLUE          = 0x006495ED,   /*!<RGB_CORNFLOWERBLUE*/
    RGB_CORNSILK                = 0x00FFF8DC,   /*!<RGB_CORNSILK*/
    RGB_CRIMSON                 = 0x00DC143C,   /*!<RGB_CRIMSON*/
    RGB_CYAN                    = 0x0000FFFF,   /*!<RGB_CYAN*/
    RGB_DARKBLUE                = 0x0000008B,   /*!<RGB_DARKBLUE*/
    RGB_DARKCYAN                = 0x00008B8B,   /*!<RGB_DARKCYAN*/
    RGB_DARKGOLDENROD           = 0x00B8860B,   /*!<RGB_DARKGOLDENROD*/
    RGB_DARKGRAY                = 0x00A9A9A9,   /*!<RGB_DARKGRAY*/
    RGB_DARKGREEN               = 0x00006400,   /*!<RGB_DARKGREEN*/
    RGB_DARKKHAKI               = 0x00BDB76B,   /*!<RGB_DARKKHAKI*/
    RGB_DARKMAGENTA             = 0x008B008B,   /*!<RGB_DARKMAGENTA*/
    RGB_DARKOLIVEGREEN          = 0x00556B2F,   /*!<RGB_DARKOLIVEGREEN*/
    RGB_DARKORANGE              = 0x00FF8C00,   /*!<RGB_DARKORANGE*/
    RGB_DARKORCHID              = 0x009932CC,   /*!<RGB_DARKORCHID*/
    RGB_DARKRED                 = 0x008B0000,   /*!<RGB_DARKRED*/
    RGB_DARKSALMON              = 0x00E9967A,   /*!<RGB_DARKSALMON*/
    RGB_DARKSEAGREEN            = 0x008FBC8B,   /*!<RGB_DARKSEAGREEN*/
    RGB_DARKSLATEBLUE           = 0x00483D8B,   /*!<RGB_DARKSLATEBLUE*/
    RGB_DARKSLATEGRAY           = 0x002F4F4F,   /*!<RGB_DARKSLATEGRAY*/
    RGB_DARKTURQUOISE           = 0x0000CED1,   /*!<RGB_DARKTURQUOISE*/
    RGB_DARKVIOLET              = 0x009400D3,   /*!<RGB_DARKVIOLET*/
    RGB_DEEPPINK                = 0x00FF1493,   /*!<RGB_DEEPPINK*/
    RGB_DEEPSKYBLUE             = 0x0000BFFF,   /*!<RGB_DEEPSKYBLUE*/
    RGB_DIMGRAY                 = 0x00696969,   /*!<RGB_DIMGRAY*/
    RGB_DODGERBLUE              = 0x001E90FF,   /*!<RGB_DODGERBLUE*/
    RGB_FIREBRICK               = 0x00B22222,   /*!<RGB_FIREBRICK*/
    RGB_FLORALWHITE             = 0x00FFFAF0,   /*!<RGB_FLORALWHITE*/
    RGB_FORESTGREEN             = 0x00228B22,   /*!<RGB_FORESTGREEN*/
    RGB_FUCHSIA                 = 0x00FF00FF,   /*!<RGB_FUCHSIA*/
    RGB_GAINSBORO               = 0x00DCDCDC,   /*!<RGB_GAINSBORO*/
    RGB_GHOSTWHITE              = 0x00F8F8FF,   /*!<RGB_GHOSTWHITE*/
    RGB_GOLD                    = 0x00FFD700,   /*!<金色*/
    RGB_GOLDENROD               = 0x00DAA520,   /*!<RGB_GOLDENROD*/
    RGB_GRAY                    = 0x00808080,   /*!<灰色*/
    RGB_GREEN                   = 0x00008000,   /*!<绿色*/
    RGB_GREENYELLOW             = 0x00ADFF2F,   /*!<RGB_GREENYELLOW*/
    RGB_HONEYDEW                = 0x00F0FFF0,   /*!<RGB_HONEYDEW*/
    RGB_HOTPINK                 = 0x00FF69B4,   /*!<RGB_HOTPINK*/
    RGB_INDIANRED               = 0x00CD5C5C,   /*!<RGB_INDIANRED*/
    RGB_INDIGO                  = 0x004B0082,   /*!<RGB_INDIGO*/
    RGB_IVORY                   = 0x00FFFFF0,   /*!<RGB_IVORY*/
    RGB_KHAKI                   = 0x00F0E68C,   /*!<RGB_KHAKI*/
    RGB_LAVENDER                = 0x00E6E6FA,   /*!<RGB_LAVENDER*/
    RGB_LAVENDERBLUSH           = 0x00FFF0F5,   /*!<RGB_LAVENDERBLUSH*/
    RGB_LAWNGREEN               = 0x007CFC00,   /*!<RGB_LAWNGREEN*/
    RGB_LEMONCHIFFON            = 0x00FFFACD,   /*!<RGB_LEMONCHIFFON*/
    RGB_LIGHTBLUE               = 0x00ADD8E6,   /*!<RGB_LIGHTBLUE*/
    RGB_LIGHTCORAL              = 0x00F08080,   /*!<RGB_LIGHTCORAL*/
    RGB_LIGHTCYAN               = 0x00E0FFFF,   /*!<RGB_LIGHTCYAN*/
    RGB_LIGHTGOLDENRODYELLOW    = 0x00FAFAD2,   /*!<RGB_LIGHTGOLDENRODYELLOW*/
    RGB_LIGHTGRAY               = 0x00D3D3D3,   /*!<RGB_LIGHTGRAY*/
    RGB_LIGHTGREEN              = 0x0090EE90,   /*!<RGB_LIGHTGREEN*/
    RGB_LIGHTPINK               = 0x00FFB6C1,   /*!<RGB_LIGHTPINK*/
    RGB_LIGHTSALMON             = 0x00FFA07A,   /*!<RGB_LIGHTSALMON*/
    RGB_LIGHTSEAGREEN           = 0x0020B2AA,   /*!<RGB_LIGHTSEAGREEN*/
    RGB_LIGHTSKYBLUE            = 0x0087CEFA,   /*!<RGB_LIGHTSKYBLUE*/
    RGB_LIGHTSLATEGRAY          = 0x00778899,   /*!<RGB_LIGHTSLATEGRAY*/
    RGB_LIGHTSTEELBLUE          = 0x00B0C4DE,   /*!<RGB_LIGHTSTEELBLUE*/
    RGB_LIGHTYELLOW             = 0x00FFFFE0,   /*!<RGB_LIGHTYELLOW*/
    RGB_LIME                    = 0x0000FF00,   /*!<RGB_LIME*/
    RGB_LIMEGREEN               = 0x0032CD32,   /*!<RGB_LIMEGREEN*/
    RGB_LINEN                   = 0x00FAF0E6,   /*!<RGB_LINEN*/
    RGB_MAGENTA                 = 0x00FF00FF,   /*!<RGB_MAGENTA*/
    RGB_MAROON                  = 0x00800000,   /*!<RGB_MAROON*/
    RGB_MEDIUMAQUAMARINE        = 0x0066CDAA,   /*!<RGB_MEDIUMAQUAMARINE*/
    RGB_MEDIUMBLUE              = 0x000000CD,   /*!<RGB_MEDIUMBLUE*/
    RGB_MEDIUMORCHID            = 0x00BA55D3,   /*!<RGB_MEDIUMORCHID*/
    RGB_MEDIUMPURPLE            = 0x009370DB,   /*!<RGB_MEDIUMPURPLE*/
    RGB_MEDIUMSEAGREEN          = 0x003CB371,   /*!<RGB_MEDIUMSEAGREEN*/
    RGB_MEDIUMSLATEBLUE         = 0x007B68EE,   /*!<RGB_MEDIUMSLATEBLUE*/
    RGB_MEDIUMSPRINGGREEN       = 0x0000FA9A,   /*!<RGB_MEDIUMSPRINGGREEN*/
    RGB_MEDIUMTURQUOISE         = 0x0048D1CC,   /*!<RGB_MEDIUMTURQUOISE*/
    RGB_MEDIUMVIOLETRED         = 0x00C71585,   /*!<RGB_MEDIUMVIOLETRED*/
    RGB_MIDNIGHTBLUE            = 0x00191970,   /*!<RGB_MIDNIGHTBLUE*/
    RGB_MINTCREAM               = 0x00F5FFFA,   /*!<RGB_MINTCREAM*/
    RGB_MISTYROSE               = 0x00FFE4E1,   /*!<RGB_MISTYROSE*/
    RGB_MOCCASIN                = 0x00FFE4B5,   /*!<RGB_MOCCASIN*/
    RGB_NAVAJOWHITE             = 0x00FFDEAD,   /*!<RGB_NAVAJOWHITE*/
    RGB_NAVY                    = 0x00000080,   /*!<RGB_NAVY*/
    RGB_OLDLACE                 = 0x00FDF5E6,   /*!<RGB_OLDLACE*/
    RGB_OLIVE                   = 0x00808000,   /*!<RGB_OLIVE*/
    RGB_OLIVEDRAB               = 0x006B8E23,   /*!<RGB_OLIVEDRAB*/
    RGB_ORANGE                  = 0x00FFA500,   /*!<RGB_ORANGE*/
    RGB_ORANGERED               = 0x00FF4500,   /*!<RGB_ORANGERED*/
    RGB_ORCHID                  = 0x00DA70D6,   /*!<RGB_ORCHID*/
    RGB_PALEGOLDENROD           = 0x00EEE8AA,   /*!<RGB_PALEGOLDENROD*/
    RGB_PALEGREEN               = 0x0098FB98,   /*!<RGB_PALEGREEN*/
    RGB_PALETURQUOISE           = 0x00AFEEEE,   /*!<RGB_PALETURQUOISE*/
    RGB_PALEVIOLETRED           = 0x00DB7093,   /*!<RGB_PALEVIOLETRED*/
    RGB_PAPAYAWHIP              = 0x00FFEFD5,   /*!<RGB_PAPAYAWHIP*/
    RGB_PEACHPUFF               = 0x00FFDAB9,   /*!<RGB_PEACHPUFF*/
    RGB_PERU                    = 0x00CD853F,   /*!<RGB_PERU*/
    RGB_PINK                    = 0x00FFC0CB,   /*!<RGB_PINK*/
    RGB_PLUM                    = 0x00DDA0DD,   /*!<RGB_PLUM*/
    RGB_POWDERBLUE              = 0x00B0E0E6,   /*!<RGB_POWDERBLUE*/
    RGB_PURPLE                  = 0x00800080,   /*!<RGB_PURPLE*/
    RGB_RED                     = 0x00FF0000,   /*!<红色*/
    RGB_ROSYBROWN               = 0x00BC8F8F,   /*!<RGB_ROSYBROWN*/
    RGB_ROYALBLUE               = 0x004169E1,   /*!<RGB_ROYALBLUE*/
    RGB_SADDLEBROWN             = 0x008B4513,   /*!<RGB_SADDLEBROWN*/
    RGB_SALMON                  = 0x00FA8072,   /*!<RGB_SALMON*/
    RGB_SANDYBROWN              = 0x00F4A460,   /*!<RGB_SANDYBROWN*/
    RGB_SEAGREEN                = 0x002E8B57,   /*!<RGB_SEAGREEN*/
    RGB_SEASHELL                = 0x00FFF5EE,   /*!<RGB_SEASHELL*/
    RGB_SIENNA                  = 0x00A0522D,   /*!<RGB_SIENNA*/
    RGB_SILVER                  = 0x00C0C0C0,   /*!<RGB_SILVER*/
    RGB_SKYBLUE                 = 0x0087CEEB,   /*!<RGB_SKYBLUE*/
    RGB_SLATEBLUE               = 0x006A5ACD,   /*!<RGB_SLATEBLUE*/
    RGB_SLATEGRAY               = 0x00708090,   /*!<RGB_SLATEGRAY*/
    RGB_SNOW                    = 0x00FFFAFA,   /*!<RGB_SNOW*/
    RGB_SPRINGGREEN             = 0x0000FF7F,   /*!<RGB_SPRINGGREEN*/
    RGB_STEELBLUE               = 0x004682B4,   /*!<RGB_STEELBLUE*/
    RGB_TAN                     = 0x00D2B48C,   /*!<RGB_TAN*/
    RGB_TEAL                    = 0x00008080,   /*!<RGB_TEAL*/
    RGB_THISTLE                 = 0x00D8BFD8,   /*!<RGB_THISTLE*/
    RGB_TOMATO                  = 0x00FF6347,   /*!<RGB_TOMATO*/
    RGB_TURQUOISE               = 0x0040E0D0,   /*!<RGB_TURQUOISE*/
    RGB_VIOLET                  = 0x00EE82EE,   /*!<RGB_VIOLET*/
    RGB_WHEAT                   = 0x00F5DEB3,   /*!<RGB_WHEAT*/
    RGB_WHITE                   = 0x00FFFFFF,   /*!<白色*/
    RGB_WHITESMOKE              = 0x00F5F5F5,   /*!<RGB_WHITESMOKE*/
    RGB_YELLOW                  = 0x00FFFF00,   /*!<黄色*/
    RGB_YELLOWGREEN             = 0x009ACD32,   /*!<RGB_YELLOWGREEN*/
    RGB_TRANSPARENT             = 0x00FFFFFF    /*!<透明*/
}ColorRGB;

/***************************************************************************************************
*\Enum          RGB565
*\Description   RGB565
***************************************************************************************************/
typedef union RGB565_un
{
    struct
    {
        u8 Red: 5;      /*!<红色值*/
        u8 Green: 6;    /*!<绿色值*/
        u8 Blue: 5;     /*!<蓝色值*/
    }RGB;
    u16 Value;          /*!<值*/
}RGB565;

typedef union RGB332_un
{
    struct
    {
        u8 Red: 3;      /*!<红色值*/
        u8 Green: 3;    /*!<绿色值*/
        u8 Blue: 2;     /*!<蓝色值*/
    }RGB;
    u8 Value;          /*!<值*/
}RGB332;

#define RGB888ToRGB565(color) ((((color) >> 19) & 0x1f) << 11) \
    |((((color) >> 10) & 0x3f) << 5) \
    |(((color) >> 3) & 0x1f)

#define RGB888ToRGB332(color) ((((color) & 0x03) << 6) | ((((color) >> 10) & 0x07) << 3) | ((((color) >> 18) & 0x07)))

#endif /*_TYPE_H*/


