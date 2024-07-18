#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define endl "\n"
#define MOD 998244353
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=5e5+10,M=2*N;
int h[N],to[M],ne[M],tot;//使用邻接表存
int fa[N][25];
int dep[N];
int ans, w[N];

void add(int a,int b){
    to[++tot] = b, ne[tot] = h[a], h[a] = tot;
}

void dfs(int u,int f){
    dep[u] = dep[f] + 1, fa[u][0] = f;
    for (int i = 1; i <= 20;i++){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = h[u]; i;i=ne[i]){
        if(to[i]!=f) dfs(to[i], u);
    }
}

int lca(int u,int v){
    if(dep[u]>dep[v]) swap(u, v);
    for (int i = 20; ~i;i--){
        if(dep[u]<=dep[v]-(1<<i)) v = fa[v][i];
    }
    if(u==v) return u;
    for (int i = 20; ~i;i--){
        if(fa[u][i]!=fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

void dfs2(int u,int f){
    for (int i = h[u]; i;i=ne[i]){
        int v = to[i];
        if(v==f) continue;
        dfs2(v, u);
        w[u] += w[v];
    }
    ans = max(ans, w[u]);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1, x, y; i < n; i++){
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    for (int i = 1, x, y; i <= m;i++){
        cin >> x >> y;
        int l = lca(x, y);
        w[x]++;
        w[y]++;
        w[l]--;
        w[fa[l][0]]--;
    }
    dfs2(1, 0);
    cout << ans << endl;
    return 0;
}