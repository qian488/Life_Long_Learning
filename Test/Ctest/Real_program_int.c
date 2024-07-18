#include<stdio.h>
#include<stdint.h>
//在inttypes.h之前加入以下宏，可以解决问题。。。?但是为什么呢?程序又不是cpp
//破案了，我使用的编译器是g++，会定义宏__cplusplus，按cpp的标准
//只有用.c文件名后缀，且使用gcc编译才不会定义宏__cplusplus
#define __STDC_FORMAT_MACROS
#include<inttypes.h>
/*
#define PRId8 "d"
#define PRId32 "d"
#define PRIu32 "u"
#define PRIu64 "I64u"
*/
//不知道为什么不把inttypes.h的相关宏定义放到该程序就运行不起来，正常来说包了头文件应该就可以直接用里面的宏的
int main()
{
    //固定宽度整数类型
    int8_t myInt8 = INT8_MAX;
    int16_t myInt16 = INT16_MAX;
    int32_t myInt32 = INT32_MAX;
    uint32_t myUInt32 = UINT32_MAX;

    uint32_t aUInt32 = 4294967295U;

    int64_t myInt64 = INT64_MAX;
    uint64_t myUInt64 = UINT64_MAX;

    printf("Size of int_16: %zu byte(s)\n", sizeof(myInt16));
    printf("Size of int_32: %zu byte(s)\n", sizeof(myInt32));
    printf("Size of uint_32: %zu byte(s)\n", sizeof(myUInt32));
    printf("Size of int_64: %zu byte(s)\n", sizeof(myInt64));
    printf("Size of uint_64: %zu byte(s)\n", sizeof(myUInt64));
    printf("=========================================================\n");
    printf("int8_t: %hhd\n", myInt8);
    printf("int32_t: %d\n", myInt32);
    printf("uint32_t: %u\n", myUInt32);
    printf("=========================================================\n");
    printf("int8_t: %" PRId8 "\n", myInt8);
    printf("int32_t: %" PRId32 "\n", myInt32);
    printf("uint32_t: %" PRIu32 "\n", myUInt32);
    printf("uint64_t: %" PRIu64 "\n", myUInt64);

    //int_least16_t
    //int_leastN_t 
    //至少有N位，可能更多，适用于需要保证最小存储容量的可移植代码

    //int_fast16_t
    //int_fastN_t
    //至少有N位，但是选择运算最快的类型，适用于需要性能敏感的场景

    //标准整数类型 -> 固定宽度整数类型
    //固定位数，不可以越界，适用于需要精确数据大小的场景
    return 0;
}