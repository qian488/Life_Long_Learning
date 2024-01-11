#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
//pta最小生成树专场--prim算法
#define INF 0x3f3f3f3f
const int N = 100;
int n, m;
int g[N][N];
int d[N];
bool vis[N];
vector<int> parent; // 记录每个顶点的父节点
vector<int> ans;

void init()
{//初始化
    memset(d, 0x3f, sizeof d);
    memset(g, 0x3f, sizeof g);
    parent.resize(N, -1);
}

int prim()
{
    int res = 0;//记录最小权值和
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (t == -1 || d[t] > d[j]))
            {
                t = j;
            }
        }

        if (i && d[t] == INF)
        {
            return INF;
        }

        if (i)
        {
            res += d[t];
            ans.push_back(t);//记录进入最小生成树的索引
        }
        vis[t] = true;

        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && g[t][j] < d[j])
            {
                d[j] = g[t][j];
                parent[j] = t;//记录父节点
            }
        }
    }

    return res;
}

int main()
{
    init();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);//存入最小权值
    }

    int t = prim();
    if (t != INF)
    {
        for (auto e:ans)
        {
            if (parent[e] != -1)
            {
                if(parent[e]<e)//保证数据是小在前
                {
                    cout << parent[e] << "," << e << "," << g[parent[e]][e] << endl;
                }
                else
                {
                    cout << e << "," << parent[e] << "," << g[parent[e]][e] << endl;
                }
            }
        }
    }

    return 0;
}