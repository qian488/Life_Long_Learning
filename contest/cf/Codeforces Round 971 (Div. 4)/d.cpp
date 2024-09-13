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

int mp[N][2];
 
void Solve() {
    int n; 
    cin >> n;
    for (int i = 0; i <= n; i ++ ) {
        mp[i][0] = mp[i][1] = 0;
    }
    int x, y;
    for (int i = 1; i <= n; i ++ ) {
        cin >> x >> y;
        mp[x][y] = 1;
    }
    ll ans = 0;
    for (int i = 0; i <= n; i ++ ) {
        if (mp[i][0] == 1 && mp[i][1] == 1) ans += n - 2;
        if (i > 0 && i < n) {
            if (mp[i][0] == 1 && mp[i - 1][1] == 1 && mp[i + 1][1] == 1) ans ++;
            if (mp[i][1] == 1 && mp[i - 1][0] == 1 && mp[i + 1][0] == 1) ans ++;
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
