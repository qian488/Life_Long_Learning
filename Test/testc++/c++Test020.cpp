#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,c=0,a[100],b[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    b[0] = 0;
    for (int i = 1; i < n; i++)
    {
        c = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[i]-a[j]>0)
           {
            c++;
           }
        }
        b[i] = c;
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}