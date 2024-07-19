#include<stdio.h>
#include<stdint.h>
#define __STDC_FORMAT_MACROS
#include<inttypes.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>
#include<windows.h>
#include<unistd.h>

int main()
{
    //进度条

    const uint32_t total_steps = 100; //总步长

    puts("处理中，请稍后：");

    for (uint32_t i = 0; i <= total_steps; i++)
    {
        printf("\r[");

        //打印进度条完整部分
        for (uint32_t  j = 0; j < i; j++)
        {
            printf("#");
        }

        for (uint32_t j = i; j < total_steps; j++)
        {
            printf(" ");
        }

        printf("] % " PRIu32 "%%", ((i * 100) / total_steps));
        //(已经传输的数据量/文件总和) * 100%

        fflush(stdout);//确保进度条及时显示
        Sleep(100);
    }

    puts("\n已完成!");
    return 0;
}