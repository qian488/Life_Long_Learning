#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 10    // 初始动态数组大小
#define INCREASE_SIZE 5 // 动态数组增长大小

typedef int ElemType; // 数据元素类型定义为整型

// 有序顺序表结构体
typedef struct {
    ElemType* data; // 动态数组
    int length;     // 当前长度
    int maxSize;    // 最大容量
} SqList;

// 初始化有序顺序表
void InitList(SqList* L) 
{
    L->data = (ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
    L->length = 0;
    L->maxSize = INIT_SIZE;
}

// 获取有序顺序表长度
int GetLength(SqList L) 
{
    return L.length;
}

// 增加有序顺序表容量
void IncreaseSize(SqList* L) 
{
    L->maxSize += INCREASE_SIZE;
    L->data = (ElemType*)realloc(L->data, L->maxSize * sizeof(ElemType));
}

// 在有序顺序表中插入元素
void ListInsert(SqList* L, ElemType x) 
{
    if (L->length >= L->maxSize)
     {
        IncreaseSize(L); // 容量不足时增加容量
    }

    int i;
    for (i = 0; i < L->length && L->data[i] < x; i++); // 找到插入位置

    // 从右向左移动元素，腾出插入位置
    for (int j = L->length; j > i; j--) 
    {
        L->data[j] = L->data[j - 1];
    }

    L->data[i] = x; // 插入新元素
    L->length++;
}

// 删除有序顺序表中的所有含x值的元素节点
void ListDelete(SqList* L, ElemType x) 
{
    int i, j;
    for (i = 0; i < L->length; i++) 
    {
        if (L->data[i] != x) 
        {
            continue; // 跳过不等于x的元素
        }
        for (j = i + 1; j < L->length; j++) 
        {
            if (L->data[j] == x) 
            {
                continue; // 跳过等于x的元素
            }
            L->data[i] = L->data[j]; // 将不等于x的元素移动到前面
            i++;
        }
    }
    L->length = i; // 更新长度
}

// 获取有序顺序表中的元素
ElemType GetElem(SqList L, int i) 
{
    if (i >= 0 && i < L.length) 
    {
        return L.data[i];
    } 
    else 
    {
        printf("索引越界\n");
        return -1;
    }
}

// 合并两个有序顺序表
void ListMerge(SqList L1, SqList L2, SqList* L3) 
{
    InitList(L3); // 初始化L3

    int i = 0, j = 0;
    while (i < L1.length && j < L2.length) 
    {
        if (L1.data[i] < L2.data[j])
        {
            ListInsert(L3, L1.data[i++]);
        } 
        else 
        {
            ListInsert(L3, L2.data[j++]);
        }
    }

    // 将剩余元素插入L3
    while (i < L1.length) 
    {
        ListInsert(L3, L1.data[i++]);
    }
    while (j < L2.length) 
    {
        ListInsert(L3, L2.data[j++]);
    }
}
