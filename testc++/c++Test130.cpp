/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
//pta最小生成树专场--最小生成树
//部分正确，过了两个样例，段错误，栈溢出，prim算法
//要么优化，要么换kruskal算法
#define INF 0x3f3f3f3f
const int N = 1010;
int n, m;
int g[N][N];
int d[N];
bool vis[N];

void init()
{
    memset(d, 0x3f, sizeof d);
    memset(g, 0x3f, sizeof g);
}

int prim()
{
    int res = 0;
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
        }
        vis[t] = true;

        for (int j = 1; j <= n; j++)
        {
            d[j] = min(d[j], g[t][j]);
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
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();
    cout<<t;
    
    return 0;
}
*/

//kruskal算法，数据有点大，要开long long

#include<iostream>
#include<algorithm>
using namespace std;
//pta最小生成树专场--kruskal算法
#define INF 0x3f3f3f3f
typedef long long ll;
const int N = 2 * 100010, M = 5 * 100010;
int n, m;
int p[N];

struct Edge
{
    ll a, b, w;

    bool operator<(const Edge &W)const
    {
        return w < W.w;
    }
}edges[M];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
}

int find(int x)
{
    if (p[x]!=x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}

ll kruskal()
{
    init();
    ll res = 0, cnt = 0;
    for (int i = 0; i < m; i++)
    {
        ll a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if (a!=b)
        {
            p[a] = b;
            res += w;
            cnt++;
        }
        
    }
    
    if (cnt<n-1)
    {
        return INF;
    }
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    sort(edges, edges + m);
    
    ll t = kruskal();

    if (t!=INF)
    {
        cout << t;
    }
    
    return 0;
}
