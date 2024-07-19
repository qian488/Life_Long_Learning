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

void Solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> f(m + 1, vector<ll>(2, 1e18));
 
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
 
        for (int j = m; j; j--) {
            f[j][0] = min(f[j][0], f[max(0, j - x)][0] + y);
            f[j][1] = min(f[j][1], min(f[max(0, j - x)][1] + y, f[max(0, j - 2 * x)][0] + y / 2));
        }
    }
 
    cout << f[m][1];
}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    //牛客小白月赛92_E	来硬的
    return 0;
}