#include<stdio.h>

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void myquicksort(int *left,int *right)
{
    if(left>=right)
    {
        return;
    }

    int *pos = left;
    int *p1 = left + 1;
    int *p2 = right;

    while(p1<=p2)
    {
        while(p1<=p2&&*p1>=*pos)
        {
            p1++;
        }
        while(p1<=p2&&*p2<*pos)
        {
            p2--;
        }
        if(p1<p2)
        {
            swap(p1,p2);
        }
    }

    swap(pos, p2);

    myquicksort(left, p2 - 1);
    myquicksort(p2 + 1, right);
}

int main()
{
    int n;
    printf("len:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    myquicksort(a,a+n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}