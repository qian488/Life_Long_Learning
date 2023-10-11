#include<iostream>
using namespace std;
int main()
{
    int n, k,t,max=0,temp,ans,a,b,s[100000];
    cin >> n >> k;
    if (n%k==0)
    {
        t = n / k;
    }
    else
    {
        t = (n / k) + 1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        //排序
        if (s[i]>max)
        {
            temp = max;
            max = s[i];
            s[i] = temp;
        }

    }
    
    for (int i = 0 , j = n ; i < j; i+=t,j-=t)
    {
        //两边往中间分组
        
        a = s[i+t-1] - s[i];
        b = s[j-1] - s[j-t];
        if (a>b)
        {
            ans = a;
        }
        else
        {
            ans = b;
        }
        
    }
    cout << ans;
    return 0;
}