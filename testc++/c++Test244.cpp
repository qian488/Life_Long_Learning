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
int a[N],b[N];
void solve()
{
    int k, n;
    cin >> k >> n;
    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i] >> b[i];
    }
    
    cout << ans;
}

int main()
{
    ios
    solve();
    //蓝桥第 7 场 小白入门赛_5.兽之泪
    //可以暴力模拟，其实就是贪心策略+分类，看要不要打最后一个，选取打和不打的情况下的最小值即可
    return 0;
}