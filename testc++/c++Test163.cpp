#include<iostream>
#include<algorithm>
using namespace std;
//莞工集训24.01.20——C
typedef long long ll;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
ll a[N], b[N];
int main()
{
    ll n;
    cin >> n;
    ll ma, mb;
    cin >> ma;
    for(ll i=0;i<ma;i++)
    {
        cin >> a[i];
    }
    cin>>mb;
    for(ll i=0;i<mb;i++)
    {
        cin >> b[i];
    }
    ll ans = 0;
    ll t = 0;
    ll x = 1;
    for(ll i=max(ma,mb);i>0;i--)
    {
        ll A = (i < ma) ? a[i] : 0;
        ll B = (i < mb) ? b[i] : 0;
        ll temp = A - B + t;

        if(temp<0)
        {
            t = -1;
            temp += N;
        }
        else
        {
            t = 0;
        }
        ans = (ans + (temp * x) % mod) % mod;
        x = (x * N) % mod;
    }
    cout << ans % mod;
    return 0;
}