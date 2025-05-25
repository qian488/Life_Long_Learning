#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int a;
    cin>>a;
    if(400%a==0){
        cout<<(400/a)<<endl;
    }else{
        cout<<-1<<endl;
    }
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