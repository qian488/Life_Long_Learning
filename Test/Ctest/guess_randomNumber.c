#include<stdio.h>
#include<stdint.h>
#define __STDC_FORMAT_MACROS
#include<inttypes.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    uint32_t secret_num, guess, status;
    char buffer[50];

    //生成随机数
    srand(time(NULL));
    //生成1--100
    secret_num = rand() % 100 + 1;

    puts("猜猜我想的数字（1-100）？");

    do
    {
        puts("请输入：");

        fgets(buffer, sizeof(buffer), stdin);
        status = sscanf_s(buffer,"%d", &guess);

        if (status != 1)
        {
            puts("输入无效，请输入一个有效数字（1-100）");
            continue;
        }

        if (guess<secret_num)
        {
            puts("太小了");
        }
        else if (guess>secret_num)
        {
            puts("太大了");
        }
        
        
    } while (guess!=secret_num);

    printf("恭喜你，猜对啦！答案就是 %" PRIu32 "\n", secret_num);

    return 0;
}