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
ll a[N],d[N];
void Solve()
{
    ll n;
    cin>>n;
    ll maxn=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll k;
    cin>>k;
    ll ans=0;
    for(int i=1;i<=n;i++){
        int x=a[i],c=0;
        while(x>k)x=(x+2)/3,c++;
        if(x==k)d[c]++;
    }
    for(int i=0;i<=30;i++)ans=max(ans,(ll)d[i]<<i);
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
    
    //牛客小白月赛92_C	耕种时间到！
    return 0;
}