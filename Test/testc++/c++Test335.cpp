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
//最大值最小，二分？不像是
//贪心？如果贪心策略不行，那就是dp了

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    const ll inf = ll(1e18);
    vector<vector<ll>> f(n + 1, vector<ll>(k + 1, inf));
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int p = 0; p <= k; p++) {
        int mn = a[i];
        for (int j = i; p + (j - i) <= k && j < n; j++) {
          mn = min(mn, a[j]);
          f[j + 1][p + (j - i)] = min(f[j + 1][p + (j - i)], f[i][p] + ll(mn) * (j - i + 1));
        }
      }
    }
    cout << *min_element(f[n].begin(), f[n].end()) << endl;
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    //Educational Codeforces Round 165 (Rated for Div. 2)
    return 0;
}