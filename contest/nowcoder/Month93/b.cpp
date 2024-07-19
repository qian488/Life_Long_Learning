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
#define MOD 998244353
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    ll tt=0,kk=0;
    for(int i = 0;i<n;i++){
        if(a[i]>b[i]){
        tt = (tt*10+a[i]-'0')%MOD;
        kk = (kk*10+b[i]-'0')%MOD;
        }else{
        tt = (tt*10+b[i]-'0')%MOD;
        kk = (kk*10+a[i]-'0')%MOD;
        }
    }
    cout<<(tt*kk)%MOD<<endl;
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