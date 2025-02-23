#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int INF = 1e9 + 10;
const ll INF_LL = 4e18;

// 最大流 Dinic 算法实现
struct MXF {
    struct Edge {
        int from, to, rev; // 边的起点、终点和反向边索引
        ll cap, flow;      // 边的容量和流量
        bool isrev;        // 是否是反向边
        Edge(int from, int to, ll cap, int rev, bool isrev)
            : from(from), to(to), rev(rev), cap(cap), flow(0), isrev(isrev) {}
    };

    vector<vector<Edge>> graph; // 邻接表
    vector<int> level, iter;    // BFS 层次和 DFS 当前弧

    // 构造函数，初始化图
    MXF(int n) : graph(n), level(n), iter(n) {}

    // 添加边
    void add_edge(int from, int to, ll cap) {
        graph[from].emplace_back(from, to, cap, graph[to].size(), false);
        graph[to].emplace_back(to, from, 0, graph[from].size() - 1, true);
    }

    // BFS 构建层次图
    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto &e : graph[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    // DFS 寻找增广路径
    ll dfs(int v, int t, ll f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < graph[v].size(); ++i) {
            Edge &e = graph[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                ll d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    e.flow += d;
                    graph[e.to][e.rev].flow -= d;
                    return d;
                }
            }
        }
        return 0;
    }

    // 计算从源点 s 到汇点 t 的最大流
    ll flow(int s, int t) {
        ll ret = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return ret; // 如果汇点不可达，结束算法
            fill(iter.begin(), iter.end(), 0);
            ll f;
            while ((f = dfs(s, t, INF_LL)) > 0) ret += f;
        }
    }

    // 获取最小割
    vector<bool> mincut(int v = 0) {
        vector<bool> ret(graph.size());
        queue<int> q;
        q.push(v);
        ret[v] = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto &e : graph[v]) {
                if (e.cap > 0 && !ret[e.to]) {
                    ret[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        return ret;
    }

    // 获取所有边的信息
    vector<Edge> get_edges() {
        vector<Edge> ret;
        for (int i = 0; i < graph.size(); ++i) {
            for (auto &e : graph[i]) {
                if (e.isrev) continue;
                ret.push_back(e);
            }
        }
        return ret;
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    MXF mxf(n*m+2);
    int s=n*m,t=n*m+1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='#') continue;
            if((i+j)%2==0){
                mxf.add_edge(s,i*m+j,1);
                if(i>0 && a[i-1][j]=='.') mxf.add_edge(i*m+j,(i-1)*m+j,1);
                if(j>0 && a[i][j-1]=='.') mxf.add_edge(i*m+j,i*m+j-1,1);
                if(i<n-1 && a[i+1][j]=='.') mxf.add_edge(i*m+j,(i+1)*m+j,1);
                if(j<m-1 && a[i][j+1]=='.') mxf.add_edge(i*m+j,i*m+j+1,1);
            }else{
                mxf.add_edge(i*m+j,t,1);
            }
        }
    }

    cout<<mxf.flow(s,t)<<endl;
    vector<vector<char>> ans(n,vector<char>(m,'.'));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] == '#') ans[i][j] = '#';
        }
    }
    
    for(auto e:mxf.get_edges()){
        if(e.from==s || e.to==t || e.flow==0) continue;
        int x1=e.from/m,y1=e.from%m;
        int x2=e.to/m,y2=e.to%m;
        if(x1==x2){
            if(y1>y2) swap(y1,y2);
            ans[x1][y1]='>';
            ans[x2][y2]='<';
        }else{
            if(x1>x2) swap(x1,x2);
            ans[x1][y1]='v';
            ans[x2][y2]='^';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}