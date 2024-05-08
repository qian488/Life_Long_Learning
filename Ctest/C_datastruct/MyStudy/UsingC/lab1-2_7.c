#include<stdio.h>

/*
题目7-递归、栈2：背包问题的递推求解(课外选做题，P119,6-15；P70,3-25)
设有一个背包可以放入物品的重量为s，现有n件物品，重量分别为w[0],w[1],…,w[n-1]。问：能否从这n件物品中选择若干件放入此背包中使得放入的重量之和正好等于s。
如果存在一种符合上述要求的选择，则称此背包问题有解；否则，称此背包问题无解。
实验要求：
(1)用递归定义给出背包问题递推定义式(可以只给出符合条件的组合个数,不需要具体的组合信息)； 
(2)给出求解此问题的递归函数；
(3)设计测试函数进行测试；
*/

// 不用求最大或者最小或是数量？
const int N=1e6+10;

int f(){
    
    return 0;
}

// 物品重量数组，n为物品数量，s为背包容量
int w[] = {1, 3, 4, 5}; // 示例物品重量
int n = sizeof(w)/sizeof(w[0]); // 物品数量
int s = 7; // 背包容量

// 递归函数求解背包问题
int knapsack(int n, int s) {
    // 基础情况
    if (n == 0 || s == 0) {
        return s == 0;
    }
    // 递推情况
    if (w[n-1] > s) {
        return knapsack(n-1, s);
    } else {
        return knapsack(n-1, s) || knapsack(n-1, s-w[n-1]);
    }
}

int main() {
    /*
    int n,s;
    scanf("%d%d",&n,&s);
    int w[N];
    for(int i=0;i<n;i++){
        scanf("%d",w[i]);
    }
    */

    if (knapsack(n, s)) {
        printf("背包问题有解。\n");
    } else {
        printf("背包问题无解。\n");
    }

    return 0;
}
