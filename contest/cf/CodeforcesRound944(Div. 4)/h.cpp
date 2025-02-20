#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {std::ios::sync_with_stdio(0);std::cin.tie(0);}
const int N=2e5+10;
//2_sat板子题
using i64 = long long;
struct TwoSat {
    int n;
    std::vector<std::vector<int>> e;
    std::vector<bool> ans;
    TwoSat(int n) : n(n), e(2 * n), ans(n) {}
    void addClause(int u, bool f, int v, bool g) {
        e[2 * u + !f].push_back(2 * v + g);
        e[2 * v + !g].push_back(2 * u + f);
    }
    bool satisfiable() {
        std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
        std::vector<int> stk;
        int now = 0, cnt = 0;
        std::function<void(int)> tarjan = [&](int u) {
            stk.push_back(u);
            dfn[u] = low[u] = now++;
            for (auto v : e[u]) {
                if (dfn[v] == -1) {
                    tarjan(v);
                    low[u] = std::min(low[u], low[v]);
                } else if (id[v] == -1) {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                int v;
                do {
                    v = stk.back();
                    stk.pop_back();
                    id[v] = cnt;
                } while (v != u);
                ++cnt;
            }
        };
        for (int i = 0; i < 2 * n; ++i) if (dfn[i] == -1) tarjan(i);
        for (int i = 0; i < n; ++i) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            ans[i] = id[2 * i] > id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return ans; }
};

void Solve()
{
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> g(3, std::vector<int>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> g[i][j];
        }
    }
    TwoSat ts(n);
    for (int j = 0; j < n; j++) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < x; y++) {
                ts.addClause(std::abs(g[x][j]) - 1, g[x][j] > 0, std::abs(g[y][j]) - 1, g[y][j] > 0);
            }
        }
    }
    if (ts.satisfiable()) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main()
{
    ios 
    int t = 1;
    std::cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}

/*
2-SAT问题可以转化为求解强连通分量的问题，并使用图论中的算法进行求解。
具体而言，可以通过构建一个有向图，其中每个变量对应两个节点（正面和否定），然后根据逻辑表达式构建有向边。
如果变量 x 在子句 (x OR y) 中出现，那么添加一条从 ~x 的节点到 y 的节点的有向边。
然后，对这个有向图进行强连通分量的计算，例如使用Tarjan算法。
如果在同一个强连通分量中存在一个变量及其否定，那么该2-SAT问题无解。
否则，对于每个强连通分量，选择一个节点并将其赋值为真，将它的否定节点赋值为假。
这样得到的变量赋值就是满足原始逻辑表达式的解。
*/