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
const int N = 1e5 + 10;
ll n, m;
map<ll, vector<ll>> op;
ll u[N], v[N], x[N];

void Solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> u[i], u[i] += u[i - 1];
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= m; i++)
        cin >> x[i];
 
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n + 1; j++)
            op[x[i] - (u[j - 1] + 1) + 1].emplace_back(v[j - 1] - v[j]);
 
    set<ll> book = { 0 };
    ll cur = 0;
    for (auto &[k, v] : op) {
        for (auto x : v)
            cur += x;
        book.insert(cur);
    }
 
    cout << book.size();
}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    //牛客小白月赛92_F	快快乐乐剪羊毛
    return 0;
}