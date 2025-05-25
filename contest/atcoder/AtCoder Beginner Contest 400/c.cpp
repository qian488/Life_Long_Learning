#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    cout<<(ll)sqrtl(n/2)+(ll)sqrtl(n/4)<<endl;
}

int main(){
    int t=1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}