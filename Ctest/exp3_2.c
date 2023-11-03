//需要引入的文件
#include<stdio.h>
//如解答错误，注意检查错误信息提示，对比预期输出和实际输出之间的差异
int main() {
// your code
int a,b;
double x,y;
char c1,c2;
scanf("%d%d%lf%lf %c %c",&a,&b,&x,&y,&c1,&c2);

printf("a=%d,b=%d,x=%lf,y=%lf,c1=%c,c2=%c",a,b,x,y,c1,c2);
return 0;
}