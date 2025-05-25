#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

void solve(){
    string s;
    cin>>s;
    int ans=0;
    ans = max((stoi(s.substr(1,s.size()-1)) + s[0]-'0'),(stoi(s.substr(0,s.size()-1)) + s[s.size()-1]-'0'));
    cout<<ans<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}