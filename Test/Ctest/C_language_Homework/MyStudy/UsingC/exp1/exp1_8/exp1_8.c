#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#define __STDC_FORMAT_MACROS
#include<inttypes.h>
/*
程序功能：从键盘输入若干个学生数据（包括学号、姓名和成绩）保存到文本文件 a.txt 中（以负数成绩表示输入结束），然后再从该文件中读出并显示。
*/
#define MAX_NAME_LEN 50

typedef struct Student
{
    char id[10];
    char name[MAX_NAME_LEN + 1];
    double score;
    struct Student *next;
}Student;

int main() {
    FILE *file = fopen("a.txt", "w");
    Student student;

    printf("请输入学生数据(学号 姓名 成绩)，以负数成绩结束:\n");
    while (1) {
        printf("学号: ");
        scanf("%s", student.id);
        printf("姓名: ");
        scanf("%s", student.name);
        printf("成绩: ");
        scanf("%lf", &student.score);

        if (student.score < 0) {
            break;
        }
        fprintf(file, "%s %s %.1lf\n", student.id, student.name, student.score);
    }
    fclose(file);

    file = fopen("a.txt", "r");
    printf("\n从文件读出的数据:\n");
    while (fscanf(file, "%s%s%lf", student.id, student.name, &student.score) != EOF) {
        printf("学号: %s, 姓名: %s, 成绩: %.1lf\n", student.id, student.name, student.score);
    }
    fclose(file);
    
    return 0;
}