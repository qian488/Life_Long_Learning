#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a,b;
    ll sum=0;
    int maxn=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        maxn=max(maxn,x);
        if(x%2==1) a.push_back(x);
        else b.push_back(x);
        sum+=x;
    }

    if(b.size()==0||a.size()==0){
        cout<<maxn<<endl;
    }else if(a.size()==1){
        cout<<sum<<endl;
    }else{
        sum -= a.size() - 1;
        cout<<sum<<endl;
    }
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