#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"


void Solve() {
    int n;
    cin >> n;
    map<ll,vector<ll>> mp;
    for(int i = 0; i < n; i++) {
        ll a;cin>>a;
        mp[a + i].push_back(a + i + i);

    }
    queue<ll> q;
    ll ans = n;
    set<ll> vis;
    q.push(n);
    while(q.size()){
        ll u = q.front();q.pop();
        ans = max(ans,u);
        if(vis.count(u)) continue;
        vis.insert(u);

        for(auto v : mp[u]) {
            q.push(v);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        Solve();
    }
    return 0;
}
