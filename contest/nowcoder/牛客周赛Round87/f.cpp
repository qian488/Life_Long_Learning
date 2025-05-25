#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

int get(string &s){
    int n = s.length();
    vector<ll> l(n, 0), r(n, 0);
    for (int i = 1; i < n; i++) {
        l[i] = l[i - 1] + (s[i - 1] == 'o' ? 1 : 0);
    }

    for (int i = n - 2; i >= 0; i--) {
        r[i] = r[i + 1] + (s[i + 1] == 'o' ? 1 : 0);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'v') {
            ans += l[i] * r[i];
        }
    }

    return ans;
}

void solve(){
    string s;
    cin>>s;
    vector<int> idx;
    for(int i=0;i<s.size();i++){
        if(s[i]=='?'){
            idx.push_back(i);
            s[i]='o';
        }
    }
    int len = idx.size();
    int ans = get(s);
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++) s[idx[j]]='o';
        for(int j=i;j<len;j++){
            s[idx[j]]='v';
            ans=max(ans,get(s));
        }
    }

    cout << ans << endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}