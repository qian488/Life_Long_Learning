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
#define INF 0x3f3f3f3f
#define MOD 998244353
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    ll n, m;
    cin >> n >> m;
    n++;
    ll ans = 0;
    ll temp = 1;
    for(int i = 0;i<60;i++){
        temp = 1;
        temp <<= i;
        if(temp&m){
            ans += n / (temp * 2) * (temp % MOD);
            ans %= MOD;
            ll kk = max(n % (temp * 2) - temp, (ll)0) % MOD;
            ans = (ans + kk) % MOD;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
