#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin>>s;
    int sum=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='-') sum-=1;
        else if(s[i]=='*') sum*=2;
        if(sum>=2025) return cout<<"YES"<<endl,void();
    }
    return cout<<"NO"<<endl,void();
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}