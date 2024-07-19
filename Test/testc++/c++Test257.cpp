#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
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
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, 1, 0, -1};
struct Node
{
    int w;
    int x, y;
    bool operator<(const Node &u) const
    {
        return w > u.w;
    }
};
void Solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    int sx, sy, tx, ty;
    char g[n + 5][m + 5];
    int dist[n+5][m+5];
    bool vis[n+5][m+5];
    memset(vis, 0, sizeof vis);
    memset(dist, INF, sizeof dist);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            if (g[i][j]=='S')
            {
                sx = i;
                sy = j;
            }
            else if(g[i][j]=='T')
            {
                tx = i;
                ty = j;
            }
        }
        
    }

    priority_queue<Node> q;
    q.push({0, sx, sy});
    dist[sx][sy] = 0;
    while (!q.empty())
    {
        Node t = q.top();
        int x = t.x, y = t.y;
        int d = t.w;
        q.pop();
        if(vis[x][y])
            continue;
        vis[x][y] = true;
        for (int k = 1; k <= 4; k++)
        {
            int i = x + dx[k], j = y + dy[k];
            if(i>n||i<1||j>m||j<1)
                continue;
            if(i==tx&&j==ty) dist[tx][ty] = min(dist[tx][ty], dist[x][y]);

            int dd = d + (g[i][j] - '0');
            if (dd<dist[i][j])
            {
                dist[i][j] = dd;
                q.push({dd, i, j});
            }
            
        }
        
    }
    

    if (dist[tx][ty]<h)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
}

int main()
{
    ios 
    int q;
    cin >> q;
    while (q--)
    {
        Solve();
    }
    
    //牛客周赛 Round 33——E小红勇闯地下城
    //类似堆优化版的dijkstra算法
    return 0;
}