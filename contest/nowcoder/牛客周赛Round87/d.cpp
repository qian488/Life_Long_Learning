#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int>dp(n,-1e10);
    dp[0]=a[0];
    dp[1]=max(a[0]+a[1],0LL);
    dp[2]=max({a[0]+a[1]+a[2],a[0],a[2],0LL});
    for(int i=3;i<n;i++){
        dp[i]=max({dp[i-1]+a[i],dp[i-2],dp[i-3]});
    }
    cout<<dp[n-1]<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}