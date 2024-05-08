#include<stdio.h>
#include<string.h>
/*
从键盘输入若干个学生数据（包括学号、姓名和成绩）保存到二进制文件 a.dat（以负数成绩表示输入结束），然后再从该文件中读出并显示。
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

int main() {
    FILE *file = fopen("a.dat", "wb");
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

        fwrite(&student, sizeof(Student), 1, file);
    }
    fclose(file);

    file = fopen("a.dat", "rb");
    printf("\n从文件读出的数据:\n");
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        printf("学号: %s, 姓名: %s, 成绩: %.1lf\n", student.id, student.name, student.score);
    }
    fclose(file);
    return 0;
}