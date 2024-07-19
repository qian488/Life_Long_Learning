#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N = 1e6 + 10;
ll a[N],b[N];
void solve()
{
    ll k, n;
    cin >> k >> n;
    ll sum = 0, minn = INF;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i] >> b[i];
        sum += a[i];
        if(i<k-1) minn = min(minn, b[i]);
    }
    ll ans1 = 0, ans2 = 0, cnt = 0;
    sort(a, a + k - 1);
    //n<k
    for (int i = 0; cnt < n&&i<k; i++) 
    {
      if(a[i]>minn) break;
      ans1 += a[i];
      cnt++;
    }
    ans1 += (n - cnt) * minn;
    //n>k
    ans2 += sum;
    minn = min(minn, b[k - 1]);
    ans2 += (n - k) * minn;

    ll ans = min(ans1, ans2);
    cout << ans;
}

int main()
{
    ios
    solve();
    //蓝桥第 7 场 小白入门赛_5.兽之泪
    //可以暴力模拟，其实就是贪心策略+分类，看要不要打最后一个，选取打和不打的情况下的最小值即可
    //好像要看n和k的关系
    return 0;
}