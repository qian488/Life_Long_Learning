#include <stdio.h>
#include <stdlib.h>

// 插入数字并保持数组有序
void sol(int* a, int* size, int num) 
{
    *size += 1;
    a = (int*)realloc(a, (*size) * sizeof(int));

    int i, j;

    // 找到插入位置
    for (i = 0; i < *size; i++) 
    {
        if (a[i] > num) 
        {
            break;
        }
    }

    // 向后移动元素，为新数字腾出位置
    for (j = *size - 1; j > i; j--) 
    {
        a[j] = a[j - 1];
    }

    // 插入新数字
    a[i] = num;
}

int main() 
{
    int* a = (int*)malloc(9 * sizeof(int));
    // 初始化数组
    for (int i = 0; i < 9; i++) 
    {
        a[i] = (i + 1) * 10;
    }
    int size = 9;
    int num = 35;

    // 插入数字并保持数组有序
    sol(a, &size, num);

    for (int i = 0; i < size; i++) 
    {
        printf("%d ", a[i]);
    }

    free(a);

    return 0;
}