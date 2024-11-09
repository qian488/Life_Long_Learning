#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ans = n;
    for (int i = 0; i < n; i++) {
        int cnt = i;
        for (int j = i + 1; j < n; j++) {
            if(a[j]>a[i]){
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
