#include<iostream>
#include<algorithm>
using namespace std;
//莞工集训24.01.20——C
//构造？不懂
/*                   
题解链接：https://blog.csdn.net/qq_43449564/article/details/124060627
*/
typedef long long ll;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
ll a[N], b[N], s[N] = {1};
ll max(ll a,ll b)
{
    return a > b ? a : b;
}
int main()
{
    ll n;
    cin >> n;
    ll ma, mb;
    cin >> ma;
    for(ll i=ma;i>0;i--)
    {
        cin >> a[i];
    }
    cin>>mb;
    for(ll i=mb;i>0;i--)
    {
        cin >> b[i];
    }
    ll ans = 0;
    
    for(ll i=1;i<=max(ma,mb);i++)
    {
        s[i] = (max(1, max(a[i], b[i])) + 1) * s[i - 1] % mod;
        ans = (ans + s[i - 1] * (a[i] - b[i]) % mod + mod) % mod;
    }
    cout << ans ;
    return 0;
}