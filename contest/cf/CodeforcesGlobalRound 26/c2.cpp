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
#define MOD 998244353
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<ll, ll> dp;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        unordered_map<ll, ll> new_dp;

        for (auto& [tt, cnt] : dp) {
            ll new_c1 = tt + a[i];
            ll new_c2 = abs(tt + a[i]);

            new_dp[new_c1] = (new_dp[new_c1] + cnt) % MOD;
            new_dp[new_c2] = (new_dp[new_c2] + cnt) % MOD;
        }

        dp = move(new_dp);
    }

    ll max_c = 0;
    ll ways = 0;

    for (auto& [c, cnt] : dp) {
        if (c > max_c) {
            max_c = c;
            ways = cnt;
        } else if (c == max_c) {
            ways = (ways + cnt) % MOD;
        }
    }

    cout << ways % MOD << endl;
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
