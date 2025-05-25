#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int kk = (k+n-1)/n;
    int ans= m/(m-kk+1);
    cout<<ans<<endl;
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