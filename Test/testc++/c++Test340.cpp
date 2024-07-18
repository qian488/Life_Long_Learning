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
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

//求x,y，使得ax+by=gcd(a,b)
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x=1;y=0;
        return a;
    }
    ll d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}

void Solve()
{
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i <= m; i++){
        for (int j = i; j - i <= n; j += i){
            if(j-i==0) continue;
            ll kk = (i * gcd(j - i, i) ) / j;
            if(kk==0) continue;
            for (ll k = 1; k <= kk; k++){
                ll t = k / i;
                ll x = t, y = t;
                cout << t << " ";
                ll tt = exgcd(j - i, i, x, y);
                if (x >= 1 && x <= n && y >= 1 && y <= m) ans++;    
            }
            
        }
        
    }
    
    cout << ans << endl;
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    //Codeforces Round 942 (Div. 2)_D2	Reverse Card (Hard Version)
    return 0;
}