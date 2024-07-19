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
#define MOD 100000000
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;
long double f[N], ans, p;
void Solve()
{
    int n;
    cin >> n >> p;
    n /= 50;
    f[0] = 1 / p;
    f[1] = 1 / p + (1 - p) / p * f[0];
    for (int i = 0; i < n; i++) f[i] = 1 / p + (1 - p) / p * (f[i - 2] + f[i - 1]);
    for (int i = 0; i < n; i++) ans += 2 * f[i];
    ans -= f[n - 1];
    printf("%.15Lf\n", ans);
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
