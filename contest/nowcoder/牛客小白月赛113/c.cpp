#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int q;
    cin>>q;
    vector<int> v;
    bool ok = true;
    while(q--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        v.push_back(a[0]);
        for(int i=1;i<n;i++){
            v.push_back(a[i]); 
            if(a[i-1]>=a[i]){
                ok=false;
                break;
            }
        }
    }
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++){
        if(v[i]-v[i-1]!=1){
            ok=false;
            break;
        }
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}