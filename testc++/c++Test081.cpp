#include<iostream>
#include <algorithm>
using namespace std;
//部分排序
const int N = 200 + 7;
int a[N];
int main()
{
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (r*2<n)
    {
        sort(a + r, a + n - r);
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << (i == n - 1 ? "\n" : " ");
    }
    
    return 0;
}