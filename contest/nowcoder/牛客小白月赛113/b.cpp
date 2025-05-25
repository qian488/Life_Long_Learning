#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    string s;
    cin>>n>>s;
    int cnt=0;
    for(int i=1;i<n;i++){
        if(s[i-1]==s[i]) cnt++;
    }
    if(cnt>=2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}