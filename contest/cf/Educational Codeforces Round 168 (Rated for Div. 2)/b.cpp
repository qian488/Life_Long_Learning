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
#define INF (ll)2e18
#define MOD 100000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n;
    cin >> n;
    vector<string> g(2);
	cin >> g[0] >> g[1];
	int ans = 0;
	for (int i = 1; i + 1 < n; i++) {
		ans += g[0].substr(i - 1, 3) == "..." && g[1].substr(i - 1, 3) == "x.x";
		ans += g[1].substr(i - 1, 3) == "..." && g[0].substr(i - 1, 3) == "x.x";
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
