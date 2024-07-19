#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

//题目
/*
设有两个一元多项式：
p(x)= p0+p1x+p2x2+•••+pnxn 
q(x)= q0+q1x+q2x2+•••+qmxm
多项式项的系数为实数，指数为整数，设计实现一元多项式的下列操作：
①	多项式链表建立：以（系数，指数）（例如（3,0）（-1,1））方式输入项建立多项式，返回所建立的链表的头指针；在输入一个多项式时如果遇到两项指数相同，可以选择舍弃、覆盖或者系数相加操作；
②	多项式排序：将所建立的多项式按指数非递减（从小到大）进行排序（也可以在建立时保证有序，创建一个有序链表）；3,3  2,2  4,4  1,0
③	多项式相加：实现两个多项式相加操作。操作生成一个新的多项式，原有的两个多项式不变，可以返回生成的多项式的头指针；
1+2x+3x2;  3x+x3+x4;  P+Q =1+5x+3x2+x3+x4
1+2x+3x2;  -2x+x3;    P+Q =1+3x2+x3
④	多项式相减：实现两个多项式相减操作。操作生成一个新的多项式，原有的两个多项式不变，可以返回生成的多项式的头指针；
⑤	多项式的输出：按照p0+p1x1+p2x2+•••+pnxn格式输出多项式；
⑥	主函数通过调用多项式链表建立函数，通过文件读取或者控制台输入两个多项式并分别输出；输出排序后的两个多项式；调用多项式相加函数实现多项式相加、相减操作，输出操作结果。
*/

//思路
//多项式加减实际上是同一种操作，加上一个负的就好

// 多项式节点定义
typedef struct PolyNode {
    double coef; // 系数
    int32_t exp; // 指数
    struct PolyNode* next;
} PolyNode;

//函数声明
PolyNode *createNode(double coef, int32_t exp);
PolyNode *createPoly();
void printPoly(PolyNode *head);
void sortPoly(PolyNode **pointerToHead);
PolyNode *addPoly(PolyNode *p1, PolyNode *p2);
PolyNode *subtractPoly(PolyNode *p1, PolyNode *p2);
void freePoly(PolyNode *head);

int main() 
{
    //输入项数，创建多项式p1,p2
    printf("请输入多项式 P 的所有项数:\n");
    PolyNode* p = createPoly();
    printf("请输入多项式 Q 的所有项数:\n");
    PolyNode* q = createPoly();

    //输出输入的多项式
    printf("多项式 P: ");
    printPoly(p);
    printf("多项式 Q: ");
    printPoly(q);

    //对多项式排序
    sortPoly(&p);
    sortPoly(&q);
    printf("排序后的 P: ");
    printPoly(p);
    printf("排序后的 Q: ");
    printPoly(q);

    //对多项式做加法
    PolyNode* sum = addPoly(p, q);
    printf("P + Q = ");
    printPoly(sum);
    freePoly(sum);

    //对多项式做减法
    PolyNode* diff = subtractPoly(p, q);
    printf("P - Q = ");
    printPoly(diff);
    freePoly(diff);

    //释放多项式链表的内存
    freePoly(p);
    freePoly(q);

    return 0;
}


// 创建多项式节点
PolyNode* createNode(double coef, int32_t exp) 
{
    PolyNode* newNode = (PolyNode*)malloc(sizeof(PolyNode));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// 建立多项式链表
PolyNode* createPoly() 
{
    PolyNode *head = NULL;
    PolyNode *tail = NULL;
    double coef;
    int32_t exp, choice;

    printf("输入格式: (系数 指数)，输入0 0结束:\n");
    scanf("%lf %" SCNd32 " ", &coef, &exp);

    while (coef != 0 || exp != 0) 
    {
        PolyNode* newNode = createNode(coef, exp);

        // 处理指数相同的情况
        PolyNode* temp = head;
        while (temp != NULL) 
        {
            if (temp->exp == exp) 
            {
                printf("指数相同，选择操作: 1. 舍弃 2. 覆盖 3. 系数相加\n");
                scanf("%" SCNd32 "", &choice);
                if (choice == 1) 
                {
                    break; // 舍弃
                }
                else if (choice == 2) 
                {
                    temp->coef = coef; // 覆盖
                    break;
                }
                else 
                {
                    temp->coef += coef; // 系数相加
                    break;
                }
            }
            temp = temp->next;
        }

        if (temp == NULL) 
        { // 插入新节点
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

        scanf("%lf %" SCNd32 "", &coef, &exp);
    }

    return head;
}

// 多项式排序
void sortPoly(PolyNode** head) 
{
    PolyNode* sorted = NULL;

    while (*head != NULL) 
    {
        PolyNode* temp = *head;
        *head = (*head)->next;

        // 插入到有序链表中
        if (sorted == NULL || temp->exp <= sorted->exp) //如果新节点的指数小于或等于当前头节点的指数,就将新节点插入到链表头部。
        {
            temp->next = sorted;
            sorted = temp;
        }
        else 
        {
            PolyNode* curr = sorted;
            while (curr->next != NULL && curr->next->exp < temp->exp) //当前节点的下一个节点的指数小于新节点的指数时,就将新节点插入到该位置。
            {
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = temp;
        }
    }

    *head = sorted;
}

// 多项式相加
PolyNode* addPoly(PolyNode* p1, PolyNode* p2) 
{
    PolyNode *head = NULL;
    PolyNode *tail = NULL;

    while (p1 != NULL && p2 != NULL) 
    {
        if (p1->exp < p2->exp) //如果 p1 的指数小于 p2 的指数,则将 p1 的项加入链表
        {
            if (head == NULL) 
            {
                head = tail = createNode(p1->coef, p1->exp);
            }
            else 
            {
                tail->next = createNode(p1->coef, p1->exp);
                tail = tail->next;
            }
            p1 = p1->next;
        }
        else if (p1->exp > p2->exp) //如果 p2 的指数小于 p1 的指数,则将 p2 的项加入链表
        {
            if (head == NULL) 
            {
                head = tail = createNode(p2->coef, p2->exp);
            }
            else 
            {
                tail->next = createNode(p2->coef, p2->exp);
                tail = tail->next;
            }
            p2 = p2->next;
        }
        else //如果 p1 的指数等于 p2 的指数,则将相加的结果加入链表
        {
            double sum = p1->coef + p2->coef;
            if (sum != 0) //sum为零就直接不加入，表示消去
            {
                if (head == NULL) 
                {
                    head = tail = createNode(sum, p1->exp);
                }
                else 
                {
                    tail->next = createNode(sum, p1->exp);
                    tail = tail->next;
                }
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) 
    {
        tail->next = createNode(p1->coef, p1->exp);
        tail = tail->next;
        p1 = p1->next;
    }

    while (p2 != NULL) 
    {
        tail->next = createNode(p2->coef, p2->exp);
        tail = tail->next;
        p2 = p2->next;
    }

    return head;
}

// 多项式相减
PolyNode* subtractPoly(PolyNode* p1, PolyNode* p2) 
{
    PolyNode *head = NULL;
    PolyNode *tail = NULL;

    // 构造 (-1) * p2
    while (p2 != NULL) 
    {
        PolyNode* newNode = createNode(-p2->coef, p2->exp);
        if (head == NULL) 
        {
            head = tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
        p2 = p2->next;
    }

    PolyNode* result = addPoly(p1, head); // p1 - p2 = p1 + (-1)*p2

    //printf("===========(-1)*p2===========\n");
    //printPoly(head);

    // 释放临时链表
    while (head != NULL) 
    {
        PolyNode* next = head->next;
        free(head);
        head = next;
    }

    return result;
}

// 输出多项式
void printPoly(PolyNode* head) 
{
    if (head == NULL) 
    {
        printf("0\n");
        return;
    }

    while (head->next != NULL) 
    {
        if(head->coef==0)
        {
            printf("0+");
        }
        else if(head->exp==0&&head->coef<0)
        {
            printf("(%.2lf)+", head->coef);
        }
        else if(head->exp==0&&head->coef>0)
        {
            printf("%.2lf+", head->coef);
        }
        else if (head->coef<0)
        {
            printf("(%.2lf)X^%" PRId32 "+", head->coef, head->exp);
        }
        else
        {
            printf("%.2lfX^%" PRId32 "+", head->coef, head->exp);
        }
        head = head->next;
    }
    //单独处理最后一项，为了换行
    if(head->coef==0)
    {
        printf("0\n");
    }
    else if(head->exp==0&&head->coef<0)
    {
        printf("(%.2lf)\n", head->coef);
    }
    else if(head->exp==0&&head->coef>0)
    {
        printf("%.2lf\n", head->coef);
    }
    else if (head->coef<0)
    {
        printf("(%.2lf)X^%" PRId32 "\n", head->coef, head->exp);
    }
    else
    {
        printf("%.2lfX^%" PRId32 "\n", head->coef, head->exp);
    }
}

// 释放多项式链表内存
void freePoly(PolyNode* head) 
{
    PolyNode* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
