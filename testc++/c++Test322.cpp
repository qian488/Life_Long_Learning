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
const int N=1e6+10;

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n;i++) cin >> g[i];

    bool flag = true;
    bool tt = true, kk = true, ii = true, jj = true;
    char c = g[0][0];
    
    for (int i = 0; i < n;i++){
        if(g[i][0]!=c) ii = false;
        if(g[i][m-1]!=c) jj = false;
    }
    
    for (int i = 0; i < m;i++){
        if(g[0][i]!=c) tt = false;
        if(g[n-1][i]!=c) kk = false;
    }
    
    if((tt!=kk)||(ii!=jj)) flag = false;
    
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
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