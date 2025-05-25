#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n+1),b(n+1);
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        sum+=b[i];
    }
    ll ans=0x3f3f3f3f3f3f3f3f;
    for(int i=0;(i*n) < 1e6;i++){
        auto T = a;
        map<ll,ll> mp;
        for(int j=1;j<=n;j++){
            T[j]-=i*j;
            mp[T[j]]+=b[j];
        }
        ll kk=0x3f3f3f3f3f3f3f3f;
        for(int j=1;j<=n;j++){
            kk=min(kk,sum - mp[T[j]]);
        }
        ans=min(ans,kk);
    }
    cout<<ans<<endl;
}

int main(){
    int t=1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}