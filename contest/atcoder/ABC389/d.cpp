#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void solve()
{
    ll r;
    cin >> r;

    // 判断一个点是否在圆内 从小数变换到整数
    auto in = [&](ll a, ll b) {
        return (2 * a + 1) * (2 * a + 1) + (2 * b + 1) * (2 * b + 1) <= 4 * r * r;
    };

    ll cnt = 0;
    ll up = r - 1;
    ll ans = (r - 1) * 4 + 1; // 边界上的方格数量

    for (ll x = 1; in(x, 1); x++) {
        while (!in(x, up)) --up; // 滑动窗口维护上边界up
        cnt += up;
    }

    ans += cnt * 4; // 内部的方格数量乘以4
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}