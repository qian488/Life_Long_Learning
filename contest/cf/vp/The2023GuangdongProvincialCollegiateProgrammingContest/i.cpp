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
int n, m;
ll ans = 0;


void Solve()
{ // 二分mex？
    cin>>n>>m;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> grid[i][j];
        }
    }
    vector<int> v(n + m - 1);
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
