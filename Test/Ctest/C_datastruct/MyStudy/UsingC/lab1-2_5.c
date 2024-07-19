#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
题目5-栈的应用：中缀表达式的求值问题（课外选做题,P70,3-24）
实验要求：
（1）先设计一个函数，把中缀表达式转化为后缀表达式；
（2）再设计一个函数，完成后缀表达式的求值计算；
（3）设计一个主函数，进行测试；
测试数据：首先假设操作数都是一位数的情况，进而扩展到操作数不受限的情况。
*/
#define MAX_SIZE 100

// 操作符优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 将中缀表达式转换为后缀表达式
void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX_SIZE];
    int top = -1;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
        } else if (infix[i] == '(') {
            stack[++top] = infix[i++];
        } else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; // Pop '('
            i++;
        } else { // 操作符
            while (top >= 0 && precedence(infix[i]) <= precedence(stack[top])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i++];
        }
    }

    while (top >= 0) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

// 后缀表达式求值
int evaluatePostfix(char* postfix) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, num1, num2, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            stack[++top] = postfix[i] - '0'; // 数字直接入栈
        } else {
            num2 = stack[top--]; // 出栈两个操作数
            num1 = stack[top--];
            switch (postfix[i]) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': result = num1 / num2; break;
            }
            stack[++top] = result; // 结果入栈
        }
    }
    return stack[top];
}

int main(){

    return 0;
}