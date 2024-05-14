#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int fresh = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                fresh++;
            }
            else if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }
    int ans = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int kk = q.size();
        bool flag = false;
        while (kk--)
        {
            auto tt = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int u = tt.first + dx[k];
                int v = tt.second + dy[k];
                if (u < 0 || u >= n || v < 0 || v >= m) continue;
                if (grid[u][v] == 1)
                {
                    fresh--;
                    grid[u][v] = 2;
                    flag = true;
                    q.push({u, v});
                }
            }
        }
        if (flag) ans++;
    }
    return fresh ? -1 : ans;
}
int main(){
    int a, b;
    cin >> a >> b;
    vector<vector<int>> grid(a, vector<int>(b));
    for (int i = 0; i < a;i++){
        for (int j = 0; j < b;j++){
            int t;
            cin>>t;
            grid[i][j] = t;
        }
    }
    int ans = orangesRotting(grid);
    cout << ans << endl;
    return 0;
}
