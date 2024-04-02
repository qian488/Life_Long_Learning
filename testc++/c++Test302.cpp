#include<bits/stdc++.h>
//蓝桥杯——岛屿个数
//双重DFS

using namespace std;
char g[55][55];
int n, m, ans = 0, vis[55][55];//因为要搜两次，所以vis分三种情况，[-1，0，1]

int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

void dfs_land(int i,int j)
{//将陆地相连部分标记
    if (vis[i][j] == -1) return;
    vis[i][j] = -1;
    for (int k = 0; k < 4; k++)//搜陆地四个方向
    {
        int nx = i + dx[k], ny = j + dy[k];
        if (nx < 0 || nx > m || ny < 0 || ny > n) continue;
        if (vis[nx][ny] == -1 || g[nx][ny] == '0') continue;
        dfs_land(nx, ny);
    }
    return;
}

void dfs_sea(int i,int j)
{
    if (vis[i][j] != 0) return;
    if (g[i][j] == '1')//找到了没标记的陆地ans++ 
    {
        dfs_land(i, j);
        ans++;
        return;
    }
    vis[i][j] = 1;
    for (int k = 0; k < 8; k++)//搜海八个方向
    {
        int nx = i + dx[k], ny = j + dy[k];
        if (vis[nx][ny] == -1 || vis[nx][ny] == 1) continue;
        if (nx < 0 || nx > m + 1 || ny < 0 || ny > n + 1) continue;
        dfs_sea(nx, ny);
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        for (int i = 0; i <= m + 1; i++)//先放满海水，大于地图一圈
        {
            for (int j = 0; j <= n + 1; j++)
            {
                g[i][j] = '0';
                vis[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; i++)// 输入图
        {
            for (int j = 1; j <= n; j++)
            { 
                cin >> g[i][j];
            }
        }
        dfs_sea(0, 0);
        cout << ans << '\n';
        ans = 0;
    }
    return 0;
}