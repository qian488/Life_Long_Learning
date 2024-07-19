#include<iostream>

using namespace std;
//牛客周赛 Round 28 --小红的好数组
//找规律+组合数学
/*
总共有四种情况：（用0表示偶数，1表示奇数）

1.000 000 000 000

2.011 011 011 011

3.101 101 101 101

4.110 110 110 110
*/
//快速幂
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e9 + 10;

ll qmi(ll m,ll k)
{
    ll res = 1 % mod, t = m;
    while(k)
    {
        if(k&1) res=res*t%mod;
        t = t * t % mod;
        k >>= 1;
    }
    return res;
}

int main()
{
    ll n, k;
    cin >> n >> k;

    ll k2 = k / 2, k1 = k - k2;

    ll r1 = qmi(k2, n);
    ll r2 = (qmi(k2, n / 3) * qmi(k1, n - n / 3)) % mod;
    ll r3 = (qmi(k2, (n + 1) / 3) * qmi(k1, n - (n + 1) / 3)) % mod;
    ll r4 = (qmi(k2, (n + 2) / 3) * qmi(k1, n - (n + 2) / 3)) % mod;

    ll ans = (r1 + r2 + r3 + r4) % mod;
    cout << ans;
    return 0;
}