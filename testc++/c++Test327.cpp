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
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    ll n,x,a=0,b=0,c=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>x;
        a+=x,b-=2*i*x,c+=i*i*x;
    }
    ll ans=1e18;
    for(ll i=1;i<=n;i++)ans=min(ans,a*i*i+b*i+c);
    cout<<ans<<endl;
}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    //牛客小白月赛92_D	探索的时光
    return 0;
}