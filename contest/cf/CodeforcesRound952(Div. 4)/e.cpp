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
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    ll x, y, z, w;
    cin >> x >> y >> z >> w;
    ll ans = 0;
    for (int i = 1; i <= x; i++) {
        if (w % i != 0) continue;
        for (int j = 1; j <= y; j++) {
            if ((w / i) % j != 0) continue;
            ll k = w / i / j;
            if (k > z) continue;
            ans = max(ans, (x - i + 1) * (y - j + 1) * (z - k + 1));
        }
    }
    cout << ans << endl;
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
