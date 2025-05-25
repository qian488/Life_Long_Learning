#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;
    ll ans=0;
    for(int i=0;i<=m;i++){
        ans += pow(n,i);
        //cout<<ans<<endl;
        if(ans>1e9){
            cout<<"inf"<<endl;
            return;
        }
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