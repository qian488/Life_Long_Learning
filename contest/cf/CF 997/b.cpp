#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (g[i][j] == '1') {
                adj[j].push_back(i); 
                vis[i]++;
            } else {
                adj[i].push_back(j); 
                vis[j]++;
            }
        }
    }

    priority_queue<int> q; 
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> ans;
    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        ans.push_back(cur + 1);  
        
        for (int ne : adj[cur]) {
            vis[ne]--;
            if (vis[ne] == 0) {
                q.push(ne);
            }
        }
    }
    
    reverse(ans.begin(), ans.end());  

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
