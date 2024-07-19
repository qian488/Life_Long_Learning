#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#define __STDC_FORMAT_MACROS
#include<inttypes.h>
//题目
/*2）程序功能：建立一个单向链表，头指针是 list，链表中每个结点包含姓名、基本工资信息，
编写 count_list 函数统计链表中超过平均基本工资的人数。
要求在主函数中建立单向链表（注：当输入基本工资为 0 时，表示输入结束。），
然后调用 count_list 函数统计链表中超过平均基本工资的人数，最后输出统计结果和平均基本工资。*/

//思路
//整体和exp1_1差不多

struct ListNode
{
    char name[50];
    double money;
    ListNode *next;
};

//函数声明
void insert(struct ListNode **pointerToHead, struct ListNode **pointerToLastNode, char *name, double money);
void printAllNodeInfo(struct ListNode *Node);
uint32_t count_list(struct ListNode *Node, double avg_money);
double avgMoney(struct ListNode *Node);

int main()
{
    double money;
    char name[50];
    ListNode *list = NULL;
    ListNode *lastNode = NULL;
    printf("请输入职工信息（输入基本工资为0时结束输入）：\n");
    while (1) 
    {
        printf("姓名：");
        scanf("%s", name);
        printf("基本工资：");
        scanf("%lf", &money);
        if (money == 0.0) break;//直到输入工资0结束输入
        insert(&list, &lastNode, name, money);
    }
    double avg = avgMoney(list);
    uint32_t count = count_list(list, avg);

    printf("超过平均工资的人数为%" PRIu32 ",平均基本工资为%.2lf\n", count, avg);

    //printAllNodeInfo(list);

    // 释放链表节点内存
    struct ListNode* current = list;
    while (current != NULL) 
    {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

//将节点信息插入链表，尾插法，保持插入的顺序，接受头指针和尾节点指针的指针作为参数，用于快速找到需要插入的节点
void insert(struct ListNode** pointerToHead,struct ListNode** pointerToLastNode, char* name, double money)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    strcpy(newNode->name, name);
    newNode->money = money;
    newNode->next = NULL;

    if (*pointerToHead == NULL)
    {
        *pointerToHead = newNode;
        *pointerToLastNode = newNode;
    }
    else
    {
        (*pointerToLastNode)->next = newNode;
        *pointerToLastNode = newNode;
    }
}

//输出所有节点的信息
void printAllNodeInfo(struct ListNode* Node) 
{
    struct ListNode *node = Node;
    while(node != NULL)
    {
        printf("姓名：%s\n", node->name);
        printf("基本工资：%.2lf\n", node->money);
        node = node->next;
    }
    printf("\n");
}

//统计链表中超过平均工资的人数
uint32_t count_list(struct ListNode *head,double avg_money)
{
    uint32_t cnt = 0;
    struct ListNode *tempNode = head;
    double avg = avg_money;

    while (tempNode!=NULL)
    {
        if (tempNode->money>avg){
            cnt++;
        }
        tempNode = tempNode->next;
    }

    return cnt;
}

//计算链表中的平均工资
double avgMoney(struct ListNode *head)
{
    uint32_t cnt = 0;
    double sum = 0;
    struct ListNode *tempNode = head;

    while (tempNode!=NULL)
    {
        cnt++;
        sum += tempNode->money;
        tempNode = tempNode->next;
    }

    double avg = sum / cnt;

    return avg;
}