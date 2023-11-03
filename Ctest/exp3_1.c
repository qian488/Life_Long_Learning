//需要引入的文件
#include<stdio.h>
#include<math.h>
#define pi 3.14
//如解答错误，注意检查错误信息提示，对比预期输出和实际输出之间的差异
int main() {
// your code

double p=0,t1,t2,t3,t4,t5;

  t1=1000*(1+5*0.03);
  printf("p1=%lf\n",t1);

  p=1000*(1+2*0.021);
  t2=p*(1+3*0.0275);
  printf("p2=%lf\n",t2);

  p=1000*(1+3*0.0275);
  t3=p*(1+2*0.021);
  printf("p3=%lf\n",t3);

  t4=1000*pow((1+0.015),5);
  printf("p4=%lf\n",t4);

  p=1000*pow((1+(0.0035/4)),4*5);
  t5=p;
  printf("p5=%lf",t5);

return 0;
}