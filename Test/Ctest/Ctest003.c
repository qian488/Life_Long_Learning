#include<stdio.h>
#define PI 3.14
int main()
{
    int h,r,s,v;
    scanf("%d %d",&h,&r);
    if(h>=1&&h<=500&&r>=1&&r<=100)
    {
    v=PI*r*r*h;
    s=20000/v;
    printf("%d",s+1);
    }
    return 0;
}