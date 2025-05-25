#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    ll a,b;
    cin>>a>>b;
    ll ans=0;
    for(int i=1;i<=a;i++){
        ans+=(2*a*b+a+b-2*b*i)/(2*a);
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