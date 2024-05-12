#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 100000000
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<ll> tt;
    if(n%2==1){ 
        tt.push_back(a.back());
        a.pop_back();
    }
    for(int i=0,j=a.size()-1;i<=j;i++,j--){
        //cout<<a[i]<<" "<<a[j]<<endl;
        tt.push_back(a[i]*a[j]);
    }
    /*
    for(auto e:tt){
        cout<<e<<" ";
    }
    cout<<endl;
    */
    sort(tt.begin(),tt.end());
    ll ans=tt.back()-tt[0];
    cout << ans << endl; 
}
int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
