#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
题目2-队列：顺序循环队列的基本操作（选做题,P70,3-22）
实验要求：
设计采取少用一个存储单元的方法解决队列满和队列空判断。设队列的元素类型为DataType，实现顺序循环队列的各种基本操作：
① 初始化队列Q；
② 判断队列Q是否为空；
③ 入队操作；
④ 出队操作；
⑤ 输出队列元素个数；
⑥ 输出队列序列；
⑦ 编写一个测试主函数，要求将若干个元素（不少于6个）入队；输出队列序列；出队若干个元素（同时输出出队元素）；通过函数调用实现以上各项操作。
测试数据：
字符型数据：假设队列的元素类型为char，建议用自己姓名的全拼。例如：依次输入zhoukx，则输出z h o u k x
*/
#define QUEUE_SIZE 100

typedef char DataType;

typedef struct {
    DataType data[QUEUE_SIZE];
    int front, rear;
    int count;
} Queue;

//函数声明
void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void push(Queue *q, DataType value);
DataType pop(Queue *q);
int queueCount(Queue *q);
void printQueue(Queue *q);

void Test(void){
    Queue q;
    initQueue(&q);

    char name[] = "kuangjh";
    int T = 3;
    int len = strlen(name);

    for (int i = 0; i < len; i++) {
        push(&q, name[i]);
    }

    printQueue(&q);

    printf("出队的元素为：");
    for (int i = 0; i < T; i++) {
        printf("%c ", pop(&q));
    }
    printf("\n");

    printQueue(&q);

    printf("队列的元素个数为 %d\n", queueCount(&q));
}

int main() 
{
    Test();
    return 0;
}

//初始化队列
void initQueue(Queue *q) {
    q->front = q->rear = 0;
    q->count = 0;
}

//判断队列空
int isEmpty(Queue *q) {
    return q->count == 0;
}

//判断队列满
int isFull(Queue *q) {
    return q->count == QUEUE_SIZE;
}

//入队操作
void push(Queue *q, DataType value) {
    if (isFull(q)) {
        printf("队列已满，无法入队\n");
        return;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->count++;
}

//出队操作
DataType pop(Queue *q) {
    if (isEmpty(q)) {
        printf("队列为空，无法出队\n");
        return '\0';
    }
    DataType value = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;
    return value;
}

//队列大小
int queueCount(Queue *q) {
    return q->count;
}

//打印队列
void printQueue(Queue *q) {
    printf("队列: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%c ", q->data[i]);
        i = (i + 1) % QUEUE_SIZE;
    }
    printf("\n");
}