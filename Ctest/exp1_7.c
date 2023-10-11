//需要引入的文件
#include<stdio.h>
//如解答错误，注意检查错误信息提示，对比预期输出和实际输出之间的差异
int main() {
// your code
int a,b,t;
scanf("%d %d",&a,&b);
t=a;
a=b;
b=t;
printf("%d %d",a,b);
return 0;
}