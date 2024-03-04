#include<iostream>
#include<cmath>
using namespace std;
//AtCoder Beginner Contest 343_C.343
//部分正确
//原因：少了个等于号--》但还有一个测试点
//那个测试点应该是cbrt()求三次方根出现了数据误差
typedef long long ll;

bool isPalindrome(ll n)
{
    ll t = n, num = 0;
    while (t != 0)
    {
        num = num * 10 + t % 10;
        t /= 10;
    }
    if (num==n)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main()
{
    ll n;
    cin>>n;

    ll ans = 0;
    for (ll i = cbrt(n); i >= 1;i--)
    {
        ll x = i * i * i;
        if (x<=n&&isPalindrome(x))
        {
            ans = x;
            break;
        }
        
    }
    
    cout << ans << endl;
    return 0;
}
/*ac代码
#include<iostream>
#include<cmath>
using namespace std;
//AtCoder Beginner Contest 343_C.343

typedef long long ll;

bool isPalindrome(ll n)
{
    ll t = n, num = 0;
    while (t != 0)
    {
        num = num * 10 + t % 10;
        t /= 10;
    }
    if (num==n)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main()
{
    ll n;
    cin>>n;

    ll ans = 0;
    for (ll i = 1; i*i*i <= n;i++)
    {
        ll x = i * i * i;
        if (isPalindrome(x))
        {
            ans = x;
        }
        
    }
    
    cout << ans << endl;
    return 0;
}
*/