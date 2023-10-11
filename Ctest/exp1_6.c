//需要引入的文件
#include<stdio.h>
//如解答错误，注意检查错误信息提示，对比预期输出和实际输出之间的差异
int main() {
// your code
int a,b;
scanf("%d %d",&a,&b);
printf("%d+%d=%d\n",a,b,a+b);
printf("%d-%d=%d\n",a,b,a-b);
printf("%d*%d=%d\n",a,b,a*b);
printf("%d/%d=%d\n",a,b,a/b);
printf("%d/%d=%f",a,b,(a*1.0/b));
return 0;
}