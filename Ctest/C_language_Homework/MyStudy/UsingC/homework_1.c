#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*1）程序功能：建立一个单向链表，头指针是 list，
链表中每个结点包含姓名、基本工资信息，编写 max_list 函数查找链表中最高基本工资的职工信息。
要求在主函数中建立单向链表（注：当输入基本工资为 0 时，表示输入结束。），
然后调用 max_list 函数查找链表中最高基本工资的职工信息，最后输出查找结果。*/
//虽然说是建立单向列表，但可以使用多一个指针，用于指向插入链表的末尾，方便插入数据
struct ListNode
{
    char name[50];
    double money;
    ListNode *next;
};
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
//找到工资最大的节点
struct ListNode* max_list(struct ListNode* head)
{
    struct ListNode *maxNode = NULL;
    struct ListNode *tempNode = head;
    double maxMoney = 0;

    while (tempNode!=NULL)
    {
        if (tempNode->money>maxMoney)
        {
            maxMoney = tempNode->money;
            maxNode = tempNode;
        }
        tempNode = tempNode->next;
    }
    maxNode->money = maxMoney;
    return maxNode;
}
//显示最大节点的信息
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
//输出链表所有信息
void printNodeInfo(struct ListNode* node) 
{
    if (node != NULL) 
    {
        printf("最高基本工资的职工信息：\n");
        printf("姓名：%s\n", node->name);
        printf("基本工资：%.2lf\n", node->money);
    }
    else {printf("链表为空或没有有效的基本工资信息。\n");}
}

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
    struct ListNode *maxNode = max_list(list);
    printNodeInfo(maxNode);
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
