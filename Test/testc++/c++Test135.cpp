#include<iostream>
#include<cstring>
using namespace std;
//pta拓扑排序专场--受欢迎的牛
/*
刚开始以为是拓扑序的个数就是多少种走到最后的路线，即多少头最受欢迎的牛
后来仔细一想，感觉有点不对，1，有环的话怎么处理，2，这个关系是否真的对应
应该是有多少个最长的终点才是
后来看题解，targan算法，强连通分量算法
*/
const int N = 1000010, M = 5000010;
int idx,h[N],e[M],ne[M];
int dtime[N],low[N];
int stk[N],id[N],scc_size[N];
int outd[N];
int t = 0, top = 0, scc_cnt = 0;
bool in_stk[N];

void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void init()
{
    idx = 0;
    memset(h, -1, sizeof h);
}

void tarjan(int u) 
{
    dtime[u] = low[u] = ++t;
    stk[++top] = u, in_stk[u] = true;
    for(int i = h[u];~i;i = ne[i]) 
    {
        int j = e[i];
        if(!dtime[j]) 
        { 
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } 
        else if(in_stk[j]) 
        { 
            low[u] = min(low[u], dtime[j]);
        }
    }
    if (low[u] == dtime[u]) 
    {
        scc_cnt++; 
        int y;
        do {
            y = stk[top--];
            id[y] = scc_cnt;
            scc_size[scc_cnt]++;
            in_stk[y] = false;
        } while(y != u);
    }
}
int main() 
{
    init();
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0;i < m;i++) 
    {
        cin >> a >> b;
        add(a, b);
    }
    for(int i = 1;i <= n;i++) 
    {
        if(!dtime[i]) 
        { 
            tarjan(i);
        }
    }
    for(int i = 1;i <= n;i++) 
    {
        for(int j = h[i];~j;j = ne[j]) 
        {
            int k = e[j];
            if(id[i] != id[k])
            {
                outd[id[i]]++; 
            }
        }
    }
    int cnt = 0, ans = 0;
    for(int i = 1;i <= scc_cnt; i++) 
    {
        if(!outd[i]) 
        {
            cnt++;
            if(cnt > 1)
            {
                ans = 0;
                break;
            }
            ans += scc_size[i];
        }
    }
    cout << ans;
    return 0;
}
