#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void solve()
{
    string s;
    cin >> s;
    ll ans = (s[0]-'0') * (s.back()-'0');
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