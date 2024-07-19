#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include "SequenceList.h"

// 初始化有序顺序表
void InitList(SequenceList* L) 
{
    L->data = (i32*)malloc(INIT_SIZE * sizeof(i32));
    L->length = 0;
    L->maxSize = INIT_SIZE;
}

// 获取有序顺序表长度
int GetLength(SequenceList L) 
{
    return L.length;
}

// 增加有序顺序表容量
void IncreaseSize(SequenceList* L) 
{
    L->maxSize += INCREASE_SIZE;
    L->data = (i32*)realloc(L->data, L->maxSize * sizeof(i32));
}

// 在有序顺序表中插入元素
void ListInsert(SequenceList* L, i32 x) 
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
void ListDelete(SequenceList* L, i32 x) 
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
i32 GetElem(SequenceList L, int i) 
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
void ListMerge(SequenceList L1, SequenceList L2, SequenceList* L3) 
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