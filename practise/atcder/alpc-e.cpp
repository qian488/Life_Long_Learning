#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int INF = 1e9 + 10;
const ll INF_LL = 4e18;

// 最小費用流
// 支持负权边，但不允许存在负环。
struct MCF {
    struct Edge {
        int from, to, rev;
        ll cap, cost;
        bool isrev;
        Edge(int from, int to, ll cap, ll cost, int rev, bool isrev) : from(from), to(to), cap(cap), cost(cost), rev(rev), isrev(isrev) {}
    };

    vector<vector<Edge>> graph;
    vector<ll> dist, pot;  // dist: 最短距离，pot: 势能函数
    vector<int> pv, pe;

    MCF(int n) { graph.resize(n), dist.resize(n), pot.resize(n), pv.resize(n), pe.resize(n); }

    // 添加边
    // 增加一条从 from 到 to 的边，容量为 cap，费用为 cost
    // cost 可以为负，但图中不能有负环
    void add_edge(int from, int to, ll cap, ll cost) {
        graph[from].push_back(Edge(from, to, cap, cost, graph[to].size(), false));
        graph[to].push_back(Edge(to, from, 0, -cost, (int)graph[from].size() - 1, true));
    }

    // 获取所有边的信息
    vector<Edge> get_edges() {
        vector<Edge> ret;
        for (int i = 0; i < (int)graph.size(); i++)
            for (auto &e : graph[i])
                if (!e.isrev) ret.push_back(e);
        return ret;
    }

    // 计算最小费用流
    // 从源点 s 到汇点 t，寻找流量为 f 的最小费用流
    // 如果无法满足流量 f，则返回 INFL 表示无解
    // 时间复杂度：O(FE log V)，其中 F 是流量，E 是边数，V 是顶点数
    ll flow(int s, int t, ll f) {
        int n = graph.size();
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        fill(pot.begin(), pot.end(), 0), fill(pv.begin(), pv.end(), 0), fill(pe.begin(), pe.end(), 0);
        ll ret = 0;

        while (f > 0) {
            fill(dist.begin(), dist.end(), INF_LL);
            dist[s] = 0;
            pq.push({0, s});
            while (!pq.empty()) {
                auto [tmp, now] = pq.top();
                pq.pop();
                if (dist[now] < tmp) continue;
                for (int i = 0; i < (int)graph[now].size(); i++) {
                    auto [from, to, rev, cap, cost, isrev] = graph[now][i];
                    ll ncost = dist[now] + cost + pot[now] - pot[to];
                    if (cap > 0 && dist[to] > ncost) {
                        dist[to] = ncost, pv[to] = now, pe[to] = i;
                        pq.push({dist[to], to});
                    }
                }
            }
            if (dist[t] == INF_LL) return INF_LL;
            for (int i = 0; i < n; i++) pot[i] += dist[i];
            ll d = f;
            for (int v = t; v != s; v = pv[v]) d = min(d, graph[pv[v]][pe[v]].cap);
            f -= d, ret += d * pot[t];
            for (int v = t; v != s; v = pv[v]) {
                auto &e = graph[pv[v]][pe[v]];
                e.cap -= d, graph[v][e.rev].cap += d;
            }
        }

        return ret;
    }
};

void solve(){
    int n, k; // N: 矩阵大小，K: 每行的最大流量
    cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(n)); // 输入矩阵
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];

    MCF mcf(2 * n + 2); // 构造最小费用流对象，节点数包括虚拟源点和汇点
    int s = 2 * n, t = 2 * n + 1; // 虚拟源点和汇点

    // 构造网络流图
    for (int i = 0; i < n; i++) {
        mcf.add_edge(s, i, k, 0); // 从源点到每一行的容量为 K，费用为 0
        mcf.add_edge(i + n, t, k, 0); // 从每一列到汇点的容量为 K，费用为 0
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mcf.add_edge(i, j + n, 1, -a[i][j]); // 从行到列的边，容量为 1，费用为 -A[i][j]（负号用于最大化总和）

    ll ans = 0; // 最终答案
    vector<MCF::Edge> anse; // 存储所有边的信息
    while (true) {
        ll cost = mcf.flow(s, t, 1); // 每次推送流量为 1 的最小费用流
        if (cost > 0) break; // 如果费用大于 0，说明无法继续推送流量
        ans -= cost; // 更新总费用（负费用表示增益）
        anse = mcf.get_edges(); // 获取当前所有边的信息
    }

    cout << ans << endl; // 输出最大增益
    vector<vector<char>> ansg(n, vector<char>(n, 'X')); // 构造输出矩阵
    for (auto e : anse) {
        auto [from, to, rev, cap, cost, isrev] = e;
        if (e.from == s || e.to == t || e.cap == 0) continue; // 跳过虚拟边和未使用的边
        ansg[e.from][e.to - n] = '.'; // 标记使用的边
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << ansg[i][j]; // 输出结果矩阵
        cout << endl;
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