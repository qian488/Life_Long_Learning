#include<stdio.h>
#include<stdint.h>
#define __STDC_FORMAT_MACROS
#include<inttypes.h>

uint32_t return_days(uint32_t year, uint32_t month);
bool is_leap(uint32_t year);

int main()
{
    printf("请输入需要查询的年份和月份：\n");
    uint32_t year, month;
    scanf("%" SCNu32 " %" SCNu32 "", &year, &month);
    printf("%" PRIu32 "年%" PRIu32 "月有%" PRIu32 "天！\n", year, month, return_days(year, month));
    return 0;
}

uint32_t return_days(uint32_t year, uint32_t month)
{
    uint32_t days[] = {31, (uint32_t)(is_leap(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}

bool is_leap(uint32_t year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}