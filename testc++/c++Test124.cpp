#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
//pta_dfs专场-- Saving James Bond - Easy Version
//跳鳄鱼
const int N=105;
int n,m;
int g[N][N];
bool vis[N][N];

bool canJump(int x, int y) 
{
    int dx = x * x;
    int dy = y * y;

    return dx + dy <= m * m;
}

bool dfs(int x, int y) 
{
    vis[x][y] = true;

    for (int i = 0; i < n; i++) 
    {
        if (!vis[g[i][0]][g[i][1]]) 
        {
            if (dfs(g[i][0], g[i][1]) && canJump(g[i][0] - x, g[i][1] - y))
                return true;
        }
    }

    if (canJump(100 - x, 100 - y))return true;

    return false;
}

int main() 
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[i][0] = x;
        g[i][1] = y;
    }
    cout << (dfs(0, 0) ? "Yes" : "No") << endl;
    return 0;
}