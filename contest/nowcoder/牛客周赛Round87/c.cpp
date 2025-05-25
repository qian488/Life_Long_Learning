#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    string s;
    cin>>s;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '>') {
            if(a[i] <= 0) {
                ans++;
                a[i] = 1; 
            }
        } else if(s[i] == '<') {
            if(a[i] >= 0) {
                ans++;
                a[i] = -1; 
            }
        } else if(s[i] == 'Z' && i > 0) {
            if(a[i] * a[i-1] <= 0) {
                ans++;
                a[i] = (a[i-1] > 0) ? 1 : -1; 
            }
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