#include <iostream>

using namespace std;
//pta_dfs专场--连通数
const int N = 1000010;

int h[N], e[N], ne[N], idx = 0;
bool vis[N];
int n;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int x)
{
    vis[x] = true;
    int cnt = 1;
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!vis[j])
        {
            cnt += dfs(j);
        }
    }
    return cnt;//记录结点能搜到的个数
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //加速cin和cout
    cin >> n;
    // memst(h,-1,sizef h);
    for (int k = 0; k < n; k++)
    {//初始化
        h[k] = -1;
        vis[k] = false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char t;
            cin>>t;
            if (t == '1')
            {//1表示有i指向j的边
                add(i, j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {//遍历所有结点
        // memset(vis,0,sizeof vis);
        for (int k = 0; k < n; k++)
        {//重置vis
            vis[k] = false;
        }

        if (!vis[i])
        {
            ans += dfs(i);
        }
    }

    cout<<ans<<endl;

    return 0;
}