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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++) cin >> a[i];

    vector<int> dp(n + 1, -1e9);

    for (int i = n - 1; i >= 0; i--) {
        int t = 0;
        for (int j = 0; j < 3 && i + j < n; j++) {
            t = max(t, a[i + j] - dp[i + j + 1]);
        }
        dp[i] = t;
    }
    for(auto e:dp){
        cout << e << " ";
    }
    cout << (dp[0] > 0 ? "Alice" : "Bob") << endl;
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    //
    return 0;
}