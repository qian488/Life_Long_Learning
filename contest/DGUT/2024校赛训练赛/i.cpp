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
#include<functional>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
#define lowbit(x) ((x)&(-x))
const int N=2e5+10;

void Solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());

    vector<vector<ll>> g;
    for(auto e:v) {
        if(g.empty() || g.back()[0]%2 != e%2) {
            g.push_back({e});
        } else {
            g.back().push_back(e);
        }
    }
    
    int m=g.size();
    for(int i=0;i+1<m;i++) {
        if(g[i][0]+k<g[i+1][0]) {
            cout<<"NO";
            return;
        }
        int j=0;
        while(j<g[i+1].size() && g[i+1][j]<=g[i].back()+k) j++;
        g[i+1].erase(g[i+1].begin(),g[i+1].begin()+j-1);
    }
    cout<<(g.back().size()==1 ? "YES" : "NO");
}

int main()
{
    ios 
    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}

// 我不会写了、、、选择抄题，补题结束了