#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define endl '\n'

void solve(){
    int n,k;
    cin>>n>>k;
    vector<array<int,3>> v(n);
    vector<pair<array<int,2>,array<int,3>>> kk;
    for (int i = 0; i < n; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        v[i]={x,y,z};
    }
    vector<bool> used(n, false);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x = v[i][0]+v[j][0];
            int y = v[i][1]+v[j][1];
            int z = v[i][2]+v[j][2];
            kk.push_back({{i,j},{x,y,z}});
        }
    }
    sort(kk.begin(),kk.end(),[](pair<array<int,2>,array<int,3>> a, pair<array<int,2>,array<int,3>> b) {
        int pa = max({a.second[0],a.second[1],a.second[2]});
        int pb = max({b.second[0],b.second[1],b.second[2]});
        return pa>pb;
    });
    ll ans = 0;
    int cnt = 0;
    for(int i=0;i<kk.size();i++){
        int x = kk[i].first[0];
        int y = kk[i].first[1];
        if(used[x] || used[y]) continue;
        used[x] = true;
        used[y] = true;
        ans += max({kk[i].second[0],kk[i].second[1],kk[i].second[2]});
        cnt++;
        if(cnt == k) break;
    }
    cout<<ans<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}