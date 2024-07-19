#include <stdio.h>
#include <stdlib.h>

/*
题目1-栈：栈操作及应用：将一个非负十进制整数转换成d进制，并输出（选做题）
算法思想：十进制数N转换成其他d进制数的转换公式  N=(N DIV d)*d+N MOD d,其中：DIV为整除运算，MOD为求余运算（取模），d为进制数。
计算过程是按照低位到高位的顺序依次产生二进制的各个数位，对打印输出来说，一般应该按照从高位到低位的顺序进行，而这恰好和计算过程相反。
因此，如果设置一个顺序栈，将计算过程中得到的二进制数的各个数位顺序进栈，然后再按照出栈序列打印输出，这样就可以得到与输入相对应的二进制数。
测试数据：自己学号的后3位
*/

#define STACK_SIZE 100

typedef struct {
    int top;
    int data[STACK_SIZE];
} Stack;

//函数声明
void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
void DtoBase(int num, int base);

// 测试函数
void Test(void){
    int num = 911;  
    int base = 2;   // 转换为二进制

    DtoBase(num, base);
}

int main() 
{
    Test();
    return 0;
}

//初始化栈
void initStack(Stack *s) {
    s->top = -1;
}
//判断满
int isFull(Stack *s) {
    return s->top == STACK_SIZE - 1;
}
//判断空
int isEmpty(Stack *s) {
    return s->top == -1;
}
//入栈操作
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("栈已满，无法入栈\n");
        return;
    }
    s->data[++s->top] = value;
}
//出栈操作
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("栈为空，无法出栈\n");
        return -1;
    }
    return s->data[s->top--];
}
//十进制转Base进制
void DtoBase(int n, int base) {
    Stack s;
    initStack(&s);//初始化栈
    int num = n;
    while (num != 0) {
        push(&s, num % base);//入栈
        num /= base;
    }

    printf("十进制数%d转%d进制的结果是: ", n, base);
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));//出栈
    }
    printf("\n");
}