#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include "SequenceList.h"
//题目
/*
①	有序顺序表的操作，包括初始化，求数据元素个树，插入，删除和取数据元素。
放在头文件中（建议尝试用动态数组实现有序顺序表；注意有序顺序表的操作与课本上的操作有所不同，需要重写一些操作，如ListInsert(L,x)，不需要参数i）；
②	设计合并函数ListMerge（L1,L2,L3），其功能是把有序表L1和L2中的数据合并到L3中，要求L3中的数据依然保持有序。
(要求时间复杂度O(n), n= n1+n2，n1、n2分别为两个顺序表的长度)；
③	设计一个测试主函数实际验证所设计有序表的各项操作以及合并函数的正确性。
测试数据：
字符型或者整形：可选l,u,a,n (同学们自己名字的拼音)
*/


int main() 
{
    SequenceList L1, L2, L3;
    InitList(&L1);
    InitList(&L2);

    // 测试数据
    i32 data1[] = {'l', 'u', 'a', 'n'};
    i32 data2[] = {'l', 'a', 'n', 'u'};

    // 插入测试数据
    for (int i = 0; i < 4; i++) 
    {
        ListInsert(&L1, data1[i]);
        ListInsert(&L2, data2[i]);
    }

    printf("L1: ");
    for (int i = 0; i < GetLength(L1); i++) 
    {
        printf("%c ", GetElem(L1, i));
    }
    printf("\n");

    printf("L2: ");
    for (int i = 0; i < GetLength(L2); i++) 
    {
        printf("%c ", GetElem(L2, i));
    }
    printf("\n");

    // 测试合并函数
    ListMerge(L1, L2, &L3);
    printf("Merged L3: ");
    for (int i = 0; i < GetLength(L3); i++) 
    {
        printf("%c ", GetElem(L3, i));
    }
    printf("\n");

    // 测试删除操作
    ListDelete(&L3, 'a');
    printf("L3 after deleting 'a': ");
    for (int i = 0; i < GetLength(L3); i++) 
    {
        printf("%c ", GetElem(L3, i));
    }
    printf("\n");

    // 释放动态数组内存
    free(L1.data);
    free(L2.data);
    free(L3.data);

    return 0;
}