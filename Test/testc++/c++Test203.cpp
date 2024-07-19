#include<iostream>

using namespace std;
//莞工集训24.02.17--E
typedef long long ll;
const int MOD = 998244353;
ll fact(int n) 
{
    ll res = 1;
    for (int i = 2; i <= n; i++) 
    {
        res = (res * i) % MOD;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;

    ll ans = (n * (n - 1) / 2) % MOD;
    for (int i = 3; i <= n; i++) 
    {
        ans = (ans * i) % MOD;
    }
    cout << ans;

    return 0;
}