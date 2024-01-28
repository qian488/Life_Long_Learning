#include<iostream>
#include<set>
using namespace std;
//牛客周赛 Round 30--小红整数操作
//先暴力模拟试试，没过

typedef long long ll;
set<ll> s;
ll gcd(ll a,ll b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
    ll x, y, l, r;
    cin >> x >> y >> l >> r;
    ll t = gcd(x, y);
    
    for (int i = 1; i <= r ; i++)
    {
        if (x%i==0&&y%i==0)
        {
            x = x / i;
            y = y / i;
        }
        else
        {
            x = x * i;
            y = y * i;
        }
        if (x>=l&&x<=r)
        {
            s.insert(x);
        }
        
    }

    cout << s.size();
    return 0;
}