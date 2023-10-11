#include<stdio.h>
int main()
{
    int s,v,t,h,m;
    scanf("%d %d",&s,&v);
    t=(s/v)+10;
    h=(int)(8*60-t)/60;
    m=(int)(8*60-t)%60;
    if(h<0)
    {
        h=24+h;
        if (m<0)
        {
            m = 60 + m;
        }
        else if (0<m<1)
        {
            m = m - 1;
        }
        else
        {
            m = m;
        } 
    }
    else
    {
        h=h;
        if (m<0)
        {
            m = 60 + m;
        }
        else if (0<m<1)
        {
            m = m - 1;
        }
        else
        {
            m = m;
        } 
    }
    printf("%02d:%02d",h,m);
    return 0;
}