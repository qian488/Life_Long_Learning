#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#define __STDC_FORMAT_MACROS
#include<inttypes.h>
//题目
/*3）程序功能：建立一个单向链表，头指针是 list，
链表中每个结点包含姓名、基本工资信息，
编写 del_list 函数删除链表中等于某给定基本工资的所有结点。
要求在主函数中先建立单向链表（注：当输入基本工资为 0 时，表示输入结束。），
再输入一个给定基本工资，
然后调用 del_list 函数删除链表中等于给定基本工资的所有结点，最后输出删除后的链表信息。*/

//思路
//删除节点，不过是给节点的值，去删除，可以先找到值返回对应的节点，然后再删除，不过c没有内置map数据结构，否则可以使用map优化查找的时间
//不过还有一个不确定的点就是原链表需不需要保存？如果映射到实际生活的话，认为应该需要保留，因为可能还有恢复操作的需求
//两种都写吧
//如果U_S 1表示原链表保存，0表示原链表不保存
#define U_S 1
#define MAX_NAME_LEN 50
struct ListNode
{
    char name[50];
    double money;
    ListNode *next;
};

//函数声明
void insert(struct ListNode **pointerToHead, struct ListNode **pointerToLastNode, char *name, double money);
void printAllNodeInfo(struct ListNode *Node);
void del_list(struct ListNode *Node, double delMoney);
struct ListNode *del_list_s(struct ListNode *Node, double delMoney);
void freeList(struct ListNode *Node);

int main()
{
    double money;
    char name[MAX_NAME_LEN + 1];
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

    //这里其实可以扩展，因为可能不止删除一次
    printf("请输入需要删除的节点对应的工资：");
    double del_money;
    scanf("%lf", &del_money);

    if (U_S){
        struct ListNode *newList = del_list_s(list, del_money);
        printAllNodeInfo(newList);
        freeList(newList);
        freeList(list);
    }
    else{
        del_list(list, del_money);
        printAllNodeInfo(list);
        freeList(list);
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

//删除链表中等于delMoney的所有节点,返回新链表的头节点
struct ListNode *del_list_s(struct ListNode *head, double delMoney)
{
    struct ListNode *newList = NULL;
    struct ListNode *tempNode = head;

    return newList;
}

//删除链表中等于delMoney的所有节点
void del_list(struct ListNode *head, double delMoney)
{
    struct ListNode *tempNode = head;

}

void freeList(struct ListNode *head)
{
    // 释放链表节点内存
    struct ListNode* current = head;
    while (current != NULL) 
    {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}