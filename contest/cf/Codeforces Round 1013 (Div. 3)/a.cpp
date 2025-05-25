#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> mp(10);
    for(int i=0;i<n;i++){
        mp[a[i]]++;
        if(mp[0] >= 3 && mp[1] >= 1 && mp[2] >= 2 && mp[3] >= 1 && mp[5] >= 1) return cout<<(i+1)<<endl,void();
    }
    cout<<0<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}