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
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    ll r;
    cin >> r;
    ll cnt = 0;
    for (ll i = -r; i <= r;i++){
        ll a = ceil(sqrtl(r * r - i * i));
        ll b = (ll)sqrtl((r + 1) * (r + 1) - i * i - 1);
        cnt += (b - a + 1) * 2 - (a == 0);
    }
    cout << cnt << endl;
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