#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<vector<int>> g; 
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    g.assign(n, vector<int>());
    vis.assign(n, false);
    
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int kk = 0;
    for (int i = 0; i < n; i++){
        if (!vis[i]) {
            dfs(i);
            kk++;
        }
    }
    
    int ans = m - (n - kk);
    cout << ans << endl;
}
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}