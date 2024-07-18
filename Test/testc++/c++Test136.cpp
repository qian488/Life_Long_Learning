#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//字典序拓扑排序
const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx = 0;
int d[N];
vector<int> ans;
priority_queue<int, vector<int>, greater<int>> pq;  // 优先队列，按照从小到大的顺序出队

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void init()
{
    idx = 0;
    memset(h, -1, sizeof h);
}

void topsort()
{
    for (int i = 0; i < n; i++)
    {
        if (!d[i])
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int t = pq.top();
        pq.pop();
        //t就是拓扑序列的数
        cout << t << " ";
        // ans.push_back(t);
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (--d[j] == 0)
            {
                pq.push(j);
            }
        }
    }
    // return ans.size()==n;
}

int main()
{
    init();
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    topsort();

    return 0;
}