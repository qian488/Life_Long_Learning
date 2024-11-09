#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, m;
    cin >> n >> m;
    
    set<pair<ll, ll>> a;
    
    for(int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        a.insert({x, y});
        
        for(int j = 0; j < 8; j++) {
            ll nx = x + dx[j], ny = y + dy[j];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                a.insert({nx, ny});
            }
        }
    }
    
    ll ans = n * n - a.size();
    cout << ans << endl;
    
    return 0;
}
