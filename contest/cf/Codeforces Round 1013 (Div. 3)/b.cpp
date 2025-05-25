#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end(),greater<int>());
    vector<int> ans;
    for(int i=0;i<n;){
        int k=1;
        while ((i + k - 1) < n && k * a[i + k - 1] < x) k++;
        if(i + k - 1 >= n) break;
        if (k * a[i + k - 1] >= x) ans.push_back(k);
        i += k;
    }
    cout<<ans.size()<<endl;
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