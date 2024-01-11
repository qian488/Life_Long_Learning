#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//pta最小生成树专场--kruskal算法
#define INF 0x3f3f3f3f
typedef long long ll;
const int N = 2 * 100010, M = 5 * 100010;
int n, m;
int p[N];
vector<int> ans;
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
    init();//并查集初始化
    ll res = 0, cnt = 0;
    for (int i = 0; i < m; i++)
    {
        ll a = edges[i].a, b = edges[i].b, w = edges[i].w;

        ll x = find(a);
        ll y = find(b);
        if (x!=y)
        {
            p[x] = y;
            res += w;
            cnt++;
            ans.push_back(i);//记录下存入到最小生成树的索引
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
        //cout << t;
        for(auto e:ans)
        {
            cout<<edges[e].a<<","<<edges[e].b<<","<<edges[e].w<<endl;
        }
    }
    
    return 0;
}