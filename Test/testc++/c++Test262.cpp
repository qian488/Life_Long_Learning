#include<iostream>
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
char g[3][N];
bool vis[3][N];
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, 1, 0, -1};
int n;

bool dfs(int x,int y)
{
    if(x==2&&y==n) return true;//递归出口,搜到终点
    if(vis[x][y]) return false;//记忆化搜索，保证每个点就搜一次
    vis[x][y] = true;
    for (int k = 1; k <= 4; k++)
    {
        int i = x + dx[k], j = y + dy[k];
        if (i<1||i>2||j<1||j>n) continue;
        if (g[i][j]=='>')
        {
            if (j+1>n) return false;//向右出界
            else if(dfs(i,j+1)) return true;
        }
        else if(g[i][j]=='<')
        {
            if (j-1<1) return false;//向左出界
            else if(dfs(i,j-1)) return true;
        }
    }

    return false;
}

void Solve()
{
    cin >> n;
    for (int i = 1; i <= 2;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            cin >> g[i][j];
        }
    }
    memset(vis, 0, sizeof vis);
    if (dfs(1,1)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    ios 
    int t;
    cin >> t;
    while(t--)
    {
        Solve();
    }
    //Educational Codeforces Round 163 (Rated for Div. 2)_C.Arrow Path
    return 0;
}