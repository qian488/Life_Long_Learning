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

//求m^k mod p 时间复杂度O(logk)
ll qmi(int m,int k,int p)
{
    ll res=1%p,t=m;
    while(k)
    {
        if(k&1) res=res*t%p;
        t=t*t%p;
        k>>=1;
    }
    return res;
}

void Solve()
{
    ll m,a,b,c;
    cin>>m>>a>>b>>c;
    ll kk = m*m;
    ll aa = (m-1)*(m-2);
    ll bb = (m-1)*3;
    ll cc = 1;
    aa = aa*a;
    bb = bb*b;
    cc = cc*c;
    ll tt=(aa+bb+cc)%MOD;
    ll ans=tt*qmi(kk%MOD,MOD-2,MOD)%MOD;
    cout<<ans<<endl;
}
int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}