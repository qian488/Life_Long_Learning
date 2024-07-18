#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,p,s;
    scanf("%f %f %f",&a,&b,&c);
    p=(a+b+c)/2;
    s=pow(p*(p-a)*(p-b)*(p-c),0.5);
    printf("%.1f",s);
    return 0;
}