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
//既然要写合并的功能，那排序就用归并排序来写吧
//有点问题，之后再看。。。
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
Student *sortList(Student *head);
Student *merge(Student *list1, Student *list2);

#define ONLY_SCORE
//用个开关 ONLY_SCORE 表示只有输入成绩，不定义则表示完整学生信息
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
/*
    Student *temp = merge(list1, list2);
    printList(temp);
    printf("\n");
*/
    //排序链表
    printf("排序后的 list1 的学生成绩为：\n");
    sortList(list1);
    printList(list1);
    printf("排序后的 list2 的学生成绩为：\n");
    sortList(list2);
    printList(list2);

    //拼接链表
    printf("拼接 list1 和 list2 的结果为：\n");
    Student *newList = merge(list1, list2);
    printList(newList);

    //释放链表
    freeList(list1);
    freeList(list2);
    freeList(newList);
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
    sortList(list1);
    printList(list1);
    printf("按成绩排序后的 list2 的学生信息为：\n");
    sortList(list2);
    printList(list2);

    //拼接链表
    printf("拼接 list1 和 list2 的结果为：\n");
    Student *newList = merge(list1, list2);
    printList(newList);

    //释放链表
    freeList(list1);
    freeList(list2);
    freeList(newList);
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

//貌似排序在leetcode也是过的,那问题出现在哪
Student *sortList(Student *head)
{
    Student *temp = head;
    //链表归并排序
    if(temp == NULL || temp->next == NULL)return temp;
    else
    {
        //快慢指针找到中间节点
        Student *fast = temp->next, *slow = temp;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        Student *mid = slow->next;
        slow->next = NULL;
        Student *left = sortList(temp); // 前半段排序
        Student *right = sortList(mid); // 后半段排序
        return merge(left,right);
    }
}

//貌似有些问题，先标记一下，emmm去leetcode交合并升序链表是通过的，也就是说合并是没问题的
Student *merge(Student *list1, Student *list2)
{
    Student *head1 = list1;
    Student *head2 = list2;

    if(head1 == NULL)return head2;
    if(head2 == NULL)return head1;
    Student *res, *p;
    if(head1->score < head2->score)
    {
        res = head1; 
        head1 = head1->next;
    }
    else
    {
        res = head2; 
        head2 = head2->next;
    }
    p = res;
         
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->score < head2->score)
        {
            p->next = head1;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    if(head1 != NULL)p->next = head1;
    else if(head2 != NULL)p->next = head2;

    return res;
}
//leetcode上合并升序链表的题解
/*递归
Student *merge(Student *list1, Student *list2)
{
    if (list1==NULL) return list2;
    else if(list2==NULL) return list1;
    else if(list1->score < list2->score){
        list1->next = merge(list1->next, list2);
        return list1;
    }
    else{
        list2->next = merge(list1, list2->next);
        return list2;
    }
}
*/
/*迭代
Student *merge(Student *list1, Student *list2)
{
    Student *preHead = new Student();

    Student *pre = preHead;
    while (list1!=NULL&&list2!=NULL)
    {
        if (list1->score < list2->score)
        {
            pre->next = list1;
            list1 = list1->next;
        }else{
            pre->next = list2;
            list2 = list2->next;
        }
        pre = pre->next;
    }
    pre->next = list1 == NULL ? list2 : list1;

    return preHead->next;
}
*/