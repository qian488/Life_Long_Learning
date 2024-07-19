
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
/*
程序功能：两个非空二进制文件 a1.dat 和 a2.dat，分别保存若干学生数据（包括学号、姓名和成绩），且按成绩升序排列。
编写程序，把 a1.dat 和 a2.dat 两个文件归并到 a3.dat 文件，使得 a3.dat 文件中的学生数据也按成绩升序排列。要求如下：
① 定义 mergeFile()函数：将两个二进制文件归并成一个按成绩升序排列的新文件。
② 定义 main()函数：
先打开二进制文件 a1.dat、a2.dat、a3.dat，
再调用 mergeFile()函数将 a1.dat、a2.dat 两个文件归并到按成绩升序排列的 a3.dat 文件，
最后输出 a3.dat 文件内容。
*/

#define MAX_ID_LEN 10
#define MAX_NAME_LEN 50

typedef struct Student
{
    char id[MAX_ID_LEN + 1];
    char name[MAX_NAME_LEN + 1];
    double score;
    struct Student *next;
}Student; 

void mergeFile(FILE *f1, FILE *f2, FILE *f3) {
    Student s1, s2;
    fread(&s1, sizeof(Student), 1, f1);
    fread(&s2, sizeof(Student), 1, f2);

    while (!feof(f1) && !feof(f2)) {
        if (s1.score < s2.score) {
            fwrite(&s1, sizeof(Student), 1, f3);
            fread(&s1, sizeof(Student), 1, f1);
        } else {
            fwrite(&s2, sizeof(Student), 1, f3);
            fread(&s2, sizeof(Student), 1, f2);
        }
    }

    while (!feof(f1)) {
        fwrite(&s1, sizeof(Student), 1, f3);
        fread(&s1, sizeof(Student), 1, f1);
    }

    while (!feof(f2)) {
        fwrite(&s2, sizeof(Student), 1, f3);
        fread(&s2, sizeof(Student), 1, f2);
    }
}

int main() {
    FILE *f1, *f2, *f3;
    f1 = fopen("a1.dat", "rb");
    f2 = fopen("a2.dat", "rb");
    f3 = fopen("a3.dat", "wb");

    if (f1 == NULL || f2 == NULL || f3 == NULL) {
        printf("Error!\n");
        return 1;
    }

    mergeFile(f1, f2, f3);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    f3 = fopen("a3.dat", "rb");
    Student s;
    while (fread(&s, sizeof(Student), 1, f3) == 1) {
        printf("学号: %s, 姓名: %s, 成绩: %.1f\n", s.id, s.name, s.score);
    }
    fclose(f3);

    return 0;
}
