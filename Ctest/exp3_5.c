#include<stdio.h>
#include<math.h>
int main()
{
    int a, b, c;
    double ans, p;
    scanf("%d%d%d",&a,&b,&c);
    p = (a + b + c) / 2.0;
    ans = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%lf",ans);
    return 0;
}