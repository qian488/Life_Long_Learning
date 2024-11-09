#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

void solve(){
    ll n, m, r, c;
    cin >> n >> m >> r >> c;

    ll kk = (r-1)*m + c;
    ll maxn = n * m;
    ll ans = (maxn - kk) + (n - r) * (m - 1);
    
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
