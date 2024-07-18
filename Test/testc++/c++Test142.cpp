#include<iostream>

using namespace std;
//pta数论专场--阶乘末尾0的个数
const int N = 1e9 + 10;
typedef long long ll;
ll f(ll n)
{
    ll cnt = 0;
    ll t = 5;
    while (t<=n)
    {
        cnt += n / t;
        t *= 5;
    }
    
    return cnt;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        ll ans;
        ans = f(n);
        cout << ans << endl;
    }
    
    return 0;
}