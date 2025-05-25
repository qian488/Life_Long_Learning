#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]) ans++;
    }
    cout<<ans<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}