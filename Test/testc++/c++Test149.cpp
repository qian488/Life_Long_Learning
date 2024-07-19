#include<iostream>
#include<algorithm>
using namespace std;
//蓝桥小白赛3--怪兽突击
//贪心,模拟
typedef long long ll;
const int N = 1e5 + 10;
const ll MAX=1e18;
ll a[N], b[N];
int main()
{
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    ll ans = MAX, sum = 0, minn = MAX;
    for(int i=1;i<=min(n,k);i++)
    {
        sum += a[i];
        minn = min(minn, a[i] + b[i]);
        ans = min(ans, sum + (k - i) * minn);
    }
    cout<<ans<<endl;

    return 0;
}