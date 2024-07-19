#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#define __STDC_FORMAT_MACROS
#include<inttypes.h>
/*
程序功能：编写一个程序，比较两个文本文件a1.txt和a2.txt的内容是否相同，若相同则输出“YES”，否则输出“NO”，并输出两个文件内容首次不同的行号和字符位置。
*/
#define u32 uint32_t
#define MAX_LINE_LENGTH 2048

void compareFiles(const char *file1, const char *file2) {
    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("无法打开文件\n");
    }

    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    u32 line_num = 1, char_pos = 0;

    while (fgets(line1, sizeof(line1), fp1) && fgets(line2, sizeof(line2), fp2)) {
        char_pos = 0;
        while (line1[char_pos] == line2[char_pos]) {
            if (line1[char_pos] == '\0' || line2[char_pos] == '\0') {
                break;
            }
            char_pos++;
        }

        if (line1[char_pos] != line2[char_pos]) {
            printf("NO\n");
            printf("第 %" PRIu32 " 行第 %" PRIu32 " 个字符不同\n", line_num, char_pos + 1);
            fclose(fp1);
            fclose(fp2);
        }

        line_num++;
    }

    if (fgets(line1, sizeof(line1), fp1) || fgets(line2, sizeof(line2), fp2)) {
        printf("NO\n");
        printf("文件长度不同\n");
    } else {
        printf("YES\n");
    }

    fclose(fp1);
    fclose(fp2);
}

int main() {
    compareFiles("a1.txt", "a2.txt");
    return 0;
}