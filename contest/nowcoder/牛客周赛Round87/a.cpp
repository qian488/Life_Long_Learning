#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b&&b<c) cout<<"YES"<<endl;
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