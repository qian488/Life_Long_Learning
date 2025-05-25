#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    a=" "+a;
    b=" "+b;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        if(i&1){
            cnt1+=(a[i]=='1');
            cnt2+=(b[i]=='1');
        }else{
            cnt2+=(a[i]=='1');
            cnt1+=(b[i]=='1');
        }
    }
    if(cnt1<=n/2&&cnt2<=(n+1)/2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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