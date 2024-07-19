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

ll qmi(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

void Solve()
{
    int l, r, k;
    cin >> l >> r >> k;
    if (k >= 10) {
        cout << 0 << endl;
        return;
    }
    int w = 9 / k + 1;
    ll ans = (qmi(w, r) - qmi(w, l) + MOD) % MOD;
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
