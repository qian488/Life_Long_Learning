#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#define __STDC_FORMAT_MACROS
#include<inttypes.h>
//题目
/*4）程序功能：输入若干个学生成绩（输入-1 为结束标志），
建立两个已按升序排序的单向链表，头指针分别为 list1、list2，
把两个链表拼成一个升序排序的新链表，并输出新链表信息。
要求自定义函数，实现将两个链表拼成一个链表，并返回拼组后的新链表。*/

//思路
//哦，这个不需要输入学生信息，只要输入成绩。。。？两种都写吧

#define MAXN 50

typedef struct Student
{
    uint32_t ID;
    char name[MAXN + 1];
    double score;
    struct Student *next;
}Student;

//函数声明
void freeList(Student *stu);

#define ONLY_SCORE
//用个开关表示 ONLY_SCORE表示只有输入成绩，不定义则表示完整学生信息
#ifdef ONLY_SCORE

//函数声明
Student *createNode(double score);
Student *createList(void);
void printList(Student *head);

int main()
{
    //创建链表
    Student *list1 = NULL;
    Student *list2 = NULL;

    printf("请输入 list1 的学生成绩（输入成绩为-1表示结束):\n");
    list1 = createList();
    printf("请输入 list2 的学生成绩（输入成绩为-1表示结束):\n");
    list2 = createList();

    //输出链表
    printf(" list1 的学生成绩为：\n");
    printList(list1);
    printf(" list2 的学生成绩为：\n");
    printList(list2);

    //排序链表
    printf("排序后的 list1 的学生成绩为：\n");

    printf("排序后的 list2 的学生成绩为：\n");

    //拼接链表
    printf("拼接 list1 和 list2 的结果为：\n");

    return 0;
}

Student *createNode(double score)
{
    Student *newNode = (Student *)malloc(sizeof(Student));
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

Student *createList(void)
{
    Student *head = NULL;
    Student *tail = NULL;
    double score;
    while (1)
    {
        printf("请输入成绩(-1表示结束)：\n");
        scanf("%lf", &score);
        if (score==-1){
            break;
        }
        Student *newNode = createNode(score);
        if (head == NULL) 
        {
            head = tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }   
    }
    return head;
}

void printList(Student *head)
{
    Student *p = head;
    while (p!=NULL)
    {
        printf("%.2lf ", p->score);
        p = p->next;
    }
    printf("\n");
}


#else 

//函数声明
Student *createNode(uint32_t id, char *name, double score);
Student *createList(void);
void printList(Student *head);

int main()
{
    //创建链表
    Student *list1 = NULL;
    Student *list2 = NULL;

    printf("请输入 list1 的学生信息（输入学号为0表示结束):\n");
    list1 = createList();
    printf("请输入 list2 的学生信息（输入学号为0表示结束):\n");
    list2 = createList();

    //输出链表
    printf(" list1 的学生信息为：\n");
    printList(list1);
    printf(" list2 的学生信息为：\n");
    printList(list2);

    //排序链表
    printf("按成绩排序后的 list1 的学生信息为：\n");

    printf("按成绩排序后的 list2 的学生信息为：\n");

    //拼接链表
    printf("拼接 list1 和 list2 的结果为：\n");
    
    return 0;
}

Student *createNode(uint32_t id, char *name, double score)
{
    Student *newNode = (Student *)malloc(sizeof(Student));
    newNode->ID = id;
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

Student *createList(void)
{
    Student *head = NULL;
    Student *tail = NULL;
    uint32_t id;
    char name[MAXN + 1];
    double score;

    while(1)
    {
        printf("请输入学号(输入0表示结束)：");
        scanf("%" SCNu32 "", &id);
        if(id==0){
            break;
        } 
        printf("请输入姓名：");
        scanf("%s", name);
        printf("请输入成绩：");
        scanf("%lf", &score);

        Student *newNode = createNode(id, name, score);
        if (head == NULL) 
        {
            head = tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}

void printList(Student *head)
{
    Student *p = head;
    for(p = head;p!=NULL;p = p->next)//遍历 
    {
        printf("学号: %" PRIu32 " 姓名：%s 成绩：%.2lf\n", p->ID, p->name, p->score); // 输出
    }
}

#endif

void freeList(Student *stu)
{
    // 释放链表节点内存
    struct Student* current = stu;
    while (current != NULL) 
    {
        struct Student* temp = current;
        current = current->next;
        free(temp);
    }
}