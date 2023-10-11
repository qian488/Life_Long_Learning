//需要引入的文件
#include<stdio.h>
#include<math.h>
//如解答错误，注意检查错误信息提示，对比预期输出和实际输出之间的差异
int main() {
// your code
int x,y;
scanf("%d",&x);
y=pow(x,2)+2*x-10;
printf("%d",y);
return 0;
}