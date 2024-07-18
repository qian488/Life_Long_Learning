#include<stdio.h>

/*
题目6-递归：折半查找问题（课外选做题,P119,6-16）
实验要求：
（1）随机生成10000个int类型的元素放在数组a中，并排序；
（2）设计折半查找问题的递归函数；
（3）设计折半查找问题的循环结构函数；
（4）设计测试主函数，测试例子至少包括一个查找成功的例子和查找不成功的例子；
（5） 分析递归函数和循环结构函数的时间复杂度；
*/

int binarysearch(int* arr,int val){
    int l,r;
    while(l+1<r){
        int mid=l+r>>1;
        if(arr[mid]<=val){
            l=mid;
        }else{
            r=mid;
        }
    }
    return l;
}

int main(){
    
    //生成随机数组
    
    //排序

    //折半查找

    //输出查找结果

    return 0;
}