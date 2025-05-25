#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) v.push_back({p[i], i});
    
    sort(v.begin(), v.end(), [](auto a, auto b){
        return a.first > b.first;
    });
    
    vector<int> rank(n);
    int kk = 0;
    int sc = -1;
    for (int i = 0; i < n; i++){
        if(i == 0 || v[i].first != sc) kk = i + 1;
        
        rank[v[i].second] = kk;
        sc = v[i].first;
    }
    
    for (int i = 0; i < n; i++) cout << rank[i] << endl;

}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}