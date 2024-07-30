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

int n;
vector<ll> a(n + 1);
vector<vector<int>> tree(n + 1);
vector<ll> ans(n + 1, 0);

void dfs(int v) {
    ll tt = a[v];
    ll kk = 0;
    for (auto e : tree[v]) {
        dfs(e);
        kk += ans[e];
        tt += a[e];
    }
    ans[v] = max(0LL, tt - kk);
}

// 不会

void Solve()
{
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; i++) {
        int fa;
        cin >> fa;
        tree[fa].push_back(i);
    }

    dfs(1);

    cout << ans[1] << endl;
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
