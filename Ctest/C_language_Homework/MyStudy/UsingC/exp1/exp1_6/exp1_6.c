#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#define __STDC_FORMAT_MACROS
#include<inttypes.h>
/*程序功能：已知文件 a.txt 存储若干文本数据，编程统计 a.txt 文件的行数、大写字母个数、小写字母个数、数字字符个数及其他字符的个数。
要求如下：
① 定义 countFile()函数：统计文本文件的行数、大写字母个数、小写字母个数、数字字符个数及其他字符的个数。
② 定义 main()函数：打开 a.txt 文件，调用 countFile()函数统计文本文件的行数、大写字母个数、小写字母个数、数字字符个数及其他字符的个数，输出统计结果。
*/
#define u32 uint32_t
void countFile(FILE *fp, u32 *lineCount, u32 *upperCount, u32 *lowerCount, u32 *digitCount, u32 *otherCount) {
    u32 ch;
    *lineCount = 0;
    *upperCount = 0;
    *lowerCount = 0;
    *digitCount = 0;
    *otherCount = 0;
    
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            (*lineCount)++;
        } else if (isupper(ch)) {
            (*upperCount)++;
        } else if (islower(ch)) {
            (*lowerCount)++;
        } else if (isdigit(ch)) {
            (*digitCount)++;
        } else {
            (*otherCount)++;
        }
    }
}

int main() 
{
    FILE *fp;
    u32 lineCount, upperCount, lowerCount, digitCount, otherCount;
    
    fp = fopen("a.txt", "r");
    if (fp == NULL) {
        printf("无法打开文件 a.txt\n");
        return 1;
    }
    
    countFile(fp, &lineCount, &upperCount, &lowerCount, &digitCount, &otherCount);
    fclose(fp);
    
    printf("统计结果:\n");
    printf("行数: %d\n", lineCount);
    printf("大写字母个数: %d\n", upperCount);
    printf("小写字母个数: %d\n", lowerCount);
    printf("数字字符个数: %d\n", digitCount);
    printf("其他字符个数: %d\n", otherCount);
    
    return 0;
}