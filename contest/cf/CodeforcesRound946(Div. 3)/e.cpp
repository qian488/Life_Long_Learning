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
    int m, x;
    cin >> m >> x;
    int ans = 0;
    int sum = 0;
    // 贪心？应该是DP...
    vector<int> c(m), h(m);
    for (int i = 0; i < m;i++){
        cin >> c[i] >> h[i];
        sum += h[i];
    }
    vector<ll> dp(N, (ll)-1e18);
    dp[0] = 0;
    for (int i = 0; i < m;i++){
        for (int j = sum; j >= 0;j--){
            if(j>=h[i]&&dp[j-h[i]]>=c[i]) dp[j] = max(dp[j], dp[j - h[i]] - c[i]);
            dp[j] += x;
        }
    }
    for (int i = 0; i <= sum;i++){
        if(dp[i]>=0) ans = i;
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
