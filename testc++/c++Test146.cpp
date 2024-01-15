#include<iostream>
#include<algorithm>
using namespace std;
//蓝桥小白赛3--召唤坤坤
typedef long long ll;
const int N = 1e5 + 10;
ll a[N];
int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll x = a[0], y = a[1], z = a[n - 1];
    ll ans = (x + z) / y;
    cout << ans;
    return 0;
}