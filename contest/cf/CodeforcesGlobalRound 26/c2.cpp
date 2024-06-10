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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<ll, ll> dp;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        map<ll, ll> new_dp;

        for (auto& [x, y] : dp) {
            new_dp[x + a[i]] = (new_dp[x + a[i]] + y) % MOD;
            new_dp[abs(x + a[i])] = (new_dp[abs(x + a[i])] + y) % MOD;
        }

        vector<pair<ll, ll>> v(new_dp.begin(), new_dp.end());
        dp.clear();
        for (int j = 0; j < v.size(); j++) {
            if (j == 0 || j == v.size() - 1) {
                dp[v[j].first] = v[j].second;
            }
        }
    }
    
    auto it = dp.rbegin();
    cout << it->second << endl;

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
