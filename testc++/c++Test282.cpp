#include<iostream>
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
const int N=1e6+10;


void Solve()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n+1);
        ll sum = 0;
        ll tt = 0;
        ll maxn = 0;
        for (ll i = 1; i <= n;i++) cin >> a[i];
        for (ll i = 1; i <= n;i++)
        {
            sum += a[i];
            tt += a[i];
            tt = max(tt, 0LL);
            maxn = max(maxn, tt);
        }
        sum = (sum % MOD + MOD) % MOD;
        maxn = maxn % MOD;
        ll kk = 1;
        for (ll i = 1; i <= k;i++)
        {
            kk = kk * 2 % MOD;
        }
        kk--;
        ll ans = (sum + maxn * kk + MOD) % MOD;
        cout << ans << endl;
    }
    
}

int main()
{
    ios 
    Solve();
    //Codeforces Round 936 (Div. 2)_B.Maximum Sum
    return 0;
}