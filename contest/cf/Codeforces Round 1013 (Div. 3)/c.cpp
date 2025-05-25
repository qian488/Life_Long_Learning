#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    if(n%2==0) return cout<<-1<<endl,void();
    vector<int> ans;
    for(int i=1;i<=n;i++) ans.push_back(i);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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