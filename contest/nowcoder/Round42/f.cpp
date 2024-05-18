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

//求m^k mod p 时间复杂度O(logk)
ll qmi(int m,int k,int p)
{
    ll res=1,t=m;
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
    ll x;
    cin >> x;
    if (x == 1) {
        cout << 0 << endl;
        return ;
    }

    ll a = 0, b = 0;
    while (x % 2 == 0) {
        x /= 2;
        a++;
    }
    while (x % 3 == 0) {
        x /= 3;
        b++;
    }

    if (x != 1) {
        cout << -1 << endl;
        return ;
    }

    vector<vector<ll>> dp(a + 1, vector<ll>(b + 1, 0));
    ll kk = qmi(2, MOD - 2, MOD);

    for (ll i = a; i >= 0; i--) {
        for (ll j = b; j >= 0; j--) {
            if (i == a && j == b) {
                dp[i][j] = 0;
            } else if (i == a) {
                dp[i][j] = (dp[i][j + 1] + 3) % MOD;
            } else if (j == b) {
                dp[i][j] = (dp[i + 1][j] + 3) % MOD;
            } else {
                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1] + 3) * kk % MOD;
            }
        }
    }

    cout << dp[0][0] << endl;
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
