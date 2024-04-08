#include<bits/stdc++.h>
//4
using namespace std;
typedef long long ll;
#define endl "\n"
const int N = 1e6 + 10;
int a[N];
int main()
{
    int ans = 0;
    
    for (int i = 1; i <= 40; i++)
    {
        a[i]=a[i-1]+i;
        cout<<a[i]<<" ";
    }
    cout << a[40];
    return 0;
}