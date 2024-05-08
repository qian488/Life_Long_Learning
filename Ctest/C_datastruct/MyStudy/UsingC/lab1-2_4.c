#include<stdio.h>
#include<stdlib.h>
/*
题目4-数组：稀疏矩阵设计（选做题,P103,5-20）
实验要求：
（1）稀疏矩阵要求采用某种压缩存储方式（建议行指针数组结构的三元组链表结构）；
（2）求两个具有相同行列数的稀疏矩阵A和B的相加矩阵C，并输出C；
（3）求出A的转置矩阵D，请输出D（转置矩阵D要求按行存储）；
（4）可以课本5-20的数据为测试例子，编写主函数进行测试
*/

typedef struct Triple {
    int row;   // 行号
    int col;   // 列号
    int value; // 元素值
    struct Triple* next; // 指向下一个三元组的指针
} Triple;

typedef struct {
    int rows;      // 矩阵行数
    int cols;      // 矩阵列数
    int nonzero;   // 非零元素个数
    Triple** rowList; // 每一行的第一个非零元素的指针数组
} SparseMatrix;

SparseMatrix* initSparseMatrix(int rows, int cols, int nonzero) {
    SparseMatrix* sm = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    sm->rows = rows;
    sm->cols = cols;
    sm->nonzero = nonzero;
    sm->rowList = (Triple**)calloc(rows, sizeof(Triple*)); // 分配行指针数组
    return sm;
}

SparseMatrix* addSparseMatrices(SparseMatrix* A, SparseMatrix* B) {
    if (A->rows != B->rows || A->cols != B->cols) {
        printf("矩阵尺寸不一致，无法相加。\n");
        return NULL;
    }

    // 初始化结果矩阵C
    SparseMatrix* C = initSparseMatrix(A->rows, A->cols, A->nonzero + B->nonzero);

    // 合并A和B中的三元组，同时进行相加操作
    Triple* pA = NULL, *pB = NULL, *pC = NULL;
    for (int i = 0; i < A->rows; i++) {
        pA = A->rowList[i];
        pB = B->rowList[i];
        while (pA && pB) {
            if (pA->col < pB->col) {
                pC = pA;
                pC->next = C->rowList[i];
                C->rowList[i] = pC;
                pA = pA->next;
            } else if (pA->col > pB->col) {
                pC = pB;
                pC->next = C->rowList[i];
                C->rowList[i] = pC;
                pB = pB->next;
            } else { // 相同列，相加
                pC = (Triple*)malloc(sizeof(Triple));
                pC->row = pA->row;
                pC->col = pA->col;
                pC->value = pA->value + pB->value;
                pC->next = C->rowList[i];
                C->rowList[i] = pC;
                pA = pA->next;
                pB = pB->next;
            }
        }
        while (pA) {
            pC = pA;
            pC->next = C->rowList[i];
            C->rowList[i] = pC;
            pA = pA->next;
        }
        while (pB) {
            pC = pB;
            pC->next = C->rowList[i];
            C->rowList[i] = pC;
            pB = pB->next;
        }
    }

    // 更新非零元素个数（此处简化处理，未去重或合并相同位置的元素）
    C->nonzero = A->nonzero + B->nonzero;

    return C;
}

SparseMatrix* transposeSparseMatrix(SparseMatrix* A) {
    SparseMatrix* D = initSparseMatrix(A->cols, A->rows, A->nonzero);

    for (int i = 0; i < A->rows; i++) {
        Triple* p = A->rowList[i];
        while (p) {
            Triple* newNode = (Triple*)malloc(sizeof(Triple));
            newNode->row = p->col;
            newNode->col = p->row;
            newNode->value = p->value;
            newNode->next = D->rowList[newNode->row];
            D->rowList[newNode->row] = newNode;
            p = p->next;
        }
    }

    return D;
}

void PrintSpareMatrix(){
    
}

int main(){


    return 0;
}