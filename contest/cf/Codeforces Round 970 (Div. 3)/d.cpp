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

void Solve()
{
    int n;
    cin >> n;
    vector<int> p(n+1);
    vector<char> color(n+1); // black or white
    vector<bool> vis(n+1, false);
    vector<int> ans(n+1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    string s;
    cin >> s;
    
    for (int i = 1; i <= n; i++) {
        color[i] = s[i-1];
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> tt;
            int cur = i;
            
            while (!vis[cur]) {
                vis[cur] = true;
                tt.push_back(cur);
                cur = p[cur];
            }
            
            int black_cnt = 0;
            for (int j : tt) {
                if (color[j] == '0') {
                    black_cnt++;
                }
            }
            
            for (int j : tt) {
                ans[j] = black_cnt;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout<<endl;
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
