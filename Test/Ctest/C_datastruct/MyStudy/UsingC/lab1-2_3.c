#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
/*
题目3-串：串的基本操作（选做题,P91,4-19）
实验要求：
（1）字符串采用动态数组存储；
（2） 设计初始化函数: 建立两个字符串String1和String2,输出两个字符串；
（3） 设计插入函数：将字符串String2的头n个字符添加到String1的尾部，输出结果；
（4）设计模式匹配函数：查找串String3在String1中的位置，若String3在String1中不存在，则插入String3在String1中的m位置上，输出结果；
（5）设计主函数通过函数调用实现以上各项操作。
测试数据：
(1)string1:    “typedefstructArcBox”
		String2:    “VertexTypedata”
		String3:     “data”
(2) String1:      “structArcBox”
		String2:       “VertexType”
		String3:       “Box”
*/

typedef struct {
    char* str;
    int length;
} String;

// 初始化字符串
void initString(String* s, const char* src) {
    s->length = strlen(src);
    s->str = (char*)malloc((s->length + 1) * sizeof(char));
    strcpy(s->str, src);
}

// 释放字符串内存
void freeString(String* s) {
    if (s->str != NULL) {
        free(s->str);
        s->str = NULL;
        s->length = 0;
    }
}

void insertString(String* dest, const String* src, int n) {
    int len = strlen(src->str);
    if (n > len) n = len; // 如果n超过src长度，则只取src的全部长度
    char* newStr = (char*)malloc((dest->length + n + 1) * sizeof(char));
    strcpy(newStr, dest->str);
    strncpy(newStr + dest->length, src->str, n);
    newStr[dest->length + n] = '\0';
    free(dest->str);
    dest->str = newStr;
    dest->length += n;
}

int findAndInsert(String* s1, const String* s3, int m) {
    char* pos = strstr(s1->str, s3->str);
    if (pos != NULL) {
        printf("String3 found at position %d in String1.\n", pos - s1->str);
    } else {
        char* newStr = (char*)malloc((s1->length + s3->length + 1) * sizeof(char));
        strncpy(newStr, s1->str, m);
        strcat(newStr, s3->str);
        strcat(newStr + m + s3->length, s1->str + m);
        free(s1->str);
        s1->str = newStr;
        s1->length += s3->length;
        printf("String3 not found, inserted at position %d.\n", m);
        return m;
    }
    return -1; // 表示未插入
}


int main(){

    return 0;
}