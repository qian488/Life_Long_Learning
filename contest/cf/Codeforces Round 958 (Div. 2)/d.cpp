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
#define INF (ll)2e18
#define MOD 100000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;
const int MX = 20;

// 树形DP

void Solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<vector<ll>> dp(n, vector<ll>(MX, INF));
    auto Dfs = [&](auto&& self, int v, int fa) -> void {
      for (int i = 0; i < MX; i++) {
        dp[v][i] = a[v] * (i + 1);
      }
      for (int u : g[v]) {
        if (u == fa) {
          continue;
        }
        self(self, u, v);
        for (int x = 0; x < MX; x++) {
          ll add = INF;
          for (int y = 0; y < MX; y++) {
            if (x != y) {
              add = min(add, dp[u][y]);
            }
          }
          dp[v][x] += add;
        }
      }
    };
    Dfs(Dfs, 0, -1);
    cout << *min_element(dp[0].begin(), dp[0].end()) << endl;
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
