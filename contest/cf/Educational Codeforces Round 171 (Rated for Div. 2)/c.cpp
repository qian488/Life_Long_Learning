#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 1LL * n * (n + 1) / 2;
    int need = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1' && need + 1 <= i) {
            ans -= i + 1;
            need++;
        } else {
            need = max(0, need - 1);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}