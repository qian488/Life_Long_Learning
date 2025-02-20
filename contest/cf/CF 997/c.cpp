#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    a[0] = a[1] = a[n - 2] = 1;
    a[2] = a[n - 1] = 2;
    for(int i = 3; i < n - 2; i++) a[i] = i;
    for(int i:a) cout << i << " ";
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
