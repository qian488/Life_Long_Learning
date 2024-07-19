#include <iostream>
#include <vector>
using namespace std;
//蓝桥杯——飞机降落
// 创建飞机结构体变量
struct plane
{
    int t, d, l;
};
bool vis[15];  // true表示飞机降落，false表示飞机未降落
bool flag;  // 标记是否全部安全降落
vector<plane> p(15);
// 深搜
void dfs(int m, int cnt, int last)  // last表示此前所有飞机降落所需的单位时间
{
    if (cnt == m)
    {
        flag = true;
        return;
    }
    for (int i = 0; i < m; i++)
    {
        if (!vis[i] && p[i].t + p[i].d >= last)  // 只有来的时刻+盘旋时间 > last 的飞机才可以安全降落
        {
            vis[i] = true;
            dfs(m, cnt + 1, max(last, p[i].t) + p[i].l);
            vis[i] = false;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> p[i].t >> p[i].d >> p[i].l;
        flag = false;
        dfs(N, 0, 0);
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
/*
#include<bits/stdc++.h>

using namespace std;

const int N = 20;

struct Plane{
    int t, d, l; //到达时间 盘旋时间 降落时间
} p[N]; //存储飞机的具体实际三种时间
bool st[N]; //遍历过程中检查是否访问过
int t, n;

bool dfs(int u, int last) //当前遍历到的“坑位” 、上一架飞机降落完毕的最早时间
{
    if(u == n)  return 1;

    for(int i = 0; i < n; i++)
    {
        int t = p[i].t, d = p[i].d, l = p[i].l;
        //t + d 为一个容忍区间大小
        if(!st[i] && t + d >= last) //当前飞机的降落时间 必须大于等于 上一架飞机的最早时间
        {
            st[i] = 1;
            if(dfs(u + 1, max(last, t) + l)) return 1;
            st[i] = 0; 
        }
    }
    return 0; //没有一种可行的方案
}
int main()
{
    cin >> t;
    
    while(t -- )
    {
        memset(st, 0, sizeof st); //状态恢复
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> p[i].t >> p[i].d >> p[i].l;
        //存储完毕，开始爆搜每一种状态
        
        if(dfs(0, 0)) puts("YES");
        else puts("NO");
    }

    return 0;
}
*/