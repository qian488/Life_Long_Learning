#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    set<ll> a;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        a.insert(x);
    }
    if(a.size()==1) return cout<<0<<endl,void();
    if(!a.count(0)) return cout<<-1<<endl,void();
    cout<<(*a.rbegin() + 2 - a.size())<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}