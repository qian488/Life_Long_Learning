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
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N=2e5+10;

ll qmi(ll m,ll k,ll p)
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
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum = 0,ans = 0;
	for (int i = 0;i < n; i++){
		cin >> a[i];
		sum = (sum + a[i]) % MOD;
		ans = (ans - a[i] * a[i]) % MOD;
	}
	ans = (ans + sum * sum) % MOD;
	ans = ans * qmi(n * (n - 1) % MOD,MOD - 2,MOD) % MOD;
	ans = (ans % MOD + MOD) % MOD;
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
    
    return 0;
}
