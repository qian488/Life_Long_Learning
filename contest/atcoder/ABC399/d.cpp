#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    vector<int> a(2*n);
    for(int i = 0;i < n * 2; i++) cin>>a[i];

    vector<vector<int>> pos(n+1);
    for(int i = 0;i < n * 2; i++) pos[a[i]].push_back(i);

    set<pair<int,int>> ans;
    for (int i = 0; i + 1 < 2 * n; i++) {
        int x = a[i], y = a[i + 1];
        if (pos[x][0] + 1 == pos[x][1]) continue;
        if (pos[y][0] + 1 == pos[y][1]) continue;
        vector<int> v{pos[x][0], pos[x][1], pos[y][0], pos[y][1]};
        sort(begin(v), end(v));
        if (v[0] + 1 == v[1] && v[2] + 1 == v[3]) ans.insert({v[0],v[0]});
    }
    cout << ans.size() << endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}