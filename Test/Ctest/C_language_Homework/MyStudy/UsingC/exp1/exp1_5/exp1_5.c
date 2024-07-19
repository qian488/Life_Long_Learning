#include<stdio.h>
#include<string.h>
/*5）程序功能：已知一个数据文件 a.txt 中保存了若干个学生的计算机等级考试成绩，包括学号、姓名和成绩。
请编程读出显示文件内容并分类统计各等级人数，最后显示统计结果。
成绩等级规则：大于等于 90-A，大于等于 80-B，大于等于 70-C，大于等于 60-D，60 以下-E。
*/
#define MAXN 50

typedef struct Student
{
    char id[10];
    char name[MAXN + 1];
    double score;
    struct Student *next;
}Student;

int main()
{
    FILE *file = fopen("a.txt", "r");
    if (file == NULL) {
        printf("无法打开文件 a.txt\n");
        return 1;
    }

    int countA = 0, countB = 0, countC = 0, countD = 0, countE = 0;
    Student student;

    while (fscanf(file, "%s%s%lf", &student.id, student.name, &student.score) != EOF) {
        printf("学号:%s, 姓名:%s, 成绩:%.1lf\n", student.id, student.name, student.score);

        if (student.score >= 90) {
            countA++;
        } else if (student.score >= 80) {
            countB++;
        } else if (student.score >= 70) {
            countC++;
        } else if (student.score >= 60) {
            countD++;
        } else {
            countE++;
        }
    }

    fclose(file);

    printf("\n统计结果:\n");
    printf("A级: %d人\n", countA);
    printf("B级: %d人\n", countB);
    printf("C级: %d人\n", countC);
    printf("D级: %d人\n", countD);
    printf("E级: %d人\n", countE);

    return 0;
}