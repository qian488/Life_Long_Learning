#include<iostream>
#include<cstring>
using namespace std;
//红蓝树
//树形DP
const int N = 100010;
int head[N];
int n, tot = 0;
struct ty
{
    int t, next;
}edge[2 * N];
int f[N], col[N];
int cnt = 0;
bool flag = true;

void addedge(int x,int y)
{
    edge[++tot].t = y;
    edge[tot].next = head[x];
    head[x] = tot;
}

void dfs1(int x,int y)
{
    int son = 0;
    for (int i = head[x]; i != -1; i=edge[i].next)
    {
        if (edge[i].t==y)
        {
            continue;
        }
        son++;
        dfs1(edge[i].t, x);
    }
    if (son==0||f[x]==0)
    {
        if (f[y]!=0)
        {
            flag = false;
            return;
        }
        f[x] = f[y] = ++cnt;
    }
    
}

void dfs2(int x,int y)
{
    for (int i = head[x]; i != -1; i=edge[i].next)
    {
        if (edge[i].t==y)
        {
            continue;
        }
        if (f[edge[i].t]==f[x])
        {
            col[edge[i].t] = col[x];
        }
        else
        {
            col[edge[i].t] = col[x] ^ 1;
        }
        dfs2(edge[i].t, x);
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    memset(edge, -1, sizeof(edge));
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        addedge(x, y);
        addedge(y, x);
    }
    dfs1(1, 0);
    if (f[0]!=0||flag==false)
    {
        cout << "-1" << endl;
    }
    col[1] = 1;
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (col[i]==1)
        {
            cout << "R";
        }
        else
        {
            cout << "B";
        }
    }
    
    return 0;
}