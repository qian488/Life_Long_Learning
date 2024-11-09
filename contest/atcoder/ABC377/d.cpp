#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<int> d(m + 1, 1);
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        d[r] = max(d[r], l + 1);
    }

    for(int r = 1; r <= m; r++) {
        d[r] = max(d[r], d[r - 1]);
    }

    ll ans = 0;
    for(int r = 1; r <= m; r++) {
        ans += r - d[r] + 1;
    }
    
    cout << ans << endl;
    
    return 0;
}
