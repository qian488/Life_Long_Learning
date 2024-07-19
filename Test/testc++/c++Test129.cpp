#include<iostream>
#include<cstring>
using namespace std;
//拓扑排序模板
const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx = 0;
int q[N], d[N];

void add(int a,int b)
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
    int hh=0,tt=-1;

    for (int i = 1; i <= n; i++)
    {//看题目的结点是从0开始还是从1开始
        //cout<<d[i]<<" ";
        if (!d[i])
        {
            q[++tt] = i;
            //cout<<i<<" ";
        }
        
    }

    while (hh<=tt)
    {
        int t = q[hh++];
        //cout<<t<<" ";

        for (int i = h[t]; i != -1; i=ne[i])
        {
            int j = e[i];
            if (--d[j]==0)
            {
                q[++tt] = j;
            }
            
        }
        
    }
    // return tt=n-1;
    //如果需要判断有无拓扑序
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
    /*
    for (auto i:d)
    {
        cout<<i<<" ";
    }
    */
    topsort();
    for (int i = 0; i < n; i++) 
    {
        cout << q[i] << " ";
    }
    return 0;
}