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
const int N = 1e6 + 10;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<int> e[N];
int vis[N];
int cnt;

void dfs(int u,int v){
	if(vis[v]==u) return;

    vis[v] = u;
    cnt++;
    for (int i = 0; i < e[v].size(); i++) dfs(u, e[v][i]);

    return;
}

void Solve()
{
    int h, w, ans = 0;
    bool flag;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++) cin >> grid[i];

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if(grid[i][j]=='#') continue;
            flag = true;
            int t = i * w + j;
            for (int k = 0; k < 4; k++){
                int nx = i + dx[k], ny = j + dy[k];
                if ((nx >= 0) && (nx < h) && (ny >= 0) && (ny < w)){
                    e[t].push_back((nx)*w + (ny));
                    if(grid[nx][ny]=='#')flag=false;
                }
            }

            if(!flag){
				e[t].clear();
				continue;
			}
        }
    }
    for (int i = 0; i < (h * w); i++) vis[i] = -1;

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            int t = i * w + j;
            if ((grid[i][j] == '.') && (vis[t] < 0)){
                cnt = 0;
                dfs(t, t);
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios 
    
    Solve();
    //AtCoder Beginner Contest 351_D	Grid and Magnet
    return 0;
}