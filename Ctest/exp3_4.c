#include<stdio.h>
int main()
{
    int sign = 0, z;
    double n, x;
    scanf("%lf",&n);
    if (n<0)
    {
        n = -n;
        sign = 1;
    }
    z = (n * 10) / 10;
    x = n - z;
    if (sign==0)
    {
        printf("sign:+\n");
    }
    else
    {
        printf("sign:-\n");
    }
    printf("integral part:%d\n", z);
    printf("decimal fraction part:%f\n", x);
    return 0;
}