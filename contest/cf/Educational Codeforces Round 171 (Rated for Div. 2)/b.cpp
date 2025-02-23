#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n+10);
    for(int i=0;i<n;i++) cin >> a[i];
    ll ans = 0;
    if(n%2 == 0) {
        for(int i=0;i<n;i+=2) ans = max(ans,a[i + 1] - a[i]);
    }else{
        ans = 2e18;
        for(int i=0;i<n;i+=2){
            ll tt = 0;
            for(int j=0;j<n;j+=2){
                if(j == i) j++;
                //cout << j << " " << j + 1 << endl;
                tt = max(tt,(a[j + 1] - a[j]));
            }
            ans = min(ans,tt);
        }
    }
    cout << max(ans,1LL) << endl;
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
