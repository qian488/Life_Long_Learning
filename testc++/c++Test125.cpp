#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
//pta_dfs专场--地下迷宫探索
//部分正确，只过了一个测试点
const int N = 100010, M = N * 2;
int h[N],e[M],ne[M],idx;// 对于每个点k，开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
bool vis[N];//用于判断是否搜过
vector<int> res;
vector<int> ans;

void add(int a,int b)
{//邻接表存图
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u)
{
    vis[u]=true;//表示该点已被搜
    res.push_back(u);//存入答案数组
    //cout << u << " ";

    vector<int> tt;//用于存储邻接点时，在遍历邻接点之前对其进行排序，实现搜索的时候按从小到大的编号搜索
    for(int i=h[u];i!=-1;i=ne[i])
    {//遍历邻接表
        int j=e[i];
        tt.push_back(j);//存储所有邻接点
    }
    sort(tt.begin(),tt.end());//在遍历邻接点之前对其进行排序，实现搜索的时候按从小到大的编号搜索
    for(auto j:tt)
    {//遍历邻接点，没搜过的结点就继续dfs
        if(!vis[j]) dfs(j);
    }

    //return res.back();
}

int main()
{//初始化
    memset(h,-1,sizeof h);
    memset(vis,0,sizeof vis);
    idx=0;

    int n,m,s;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }

    //int t=dfs(s);
    //cout << t;
    dfs(s);
    for(auto e:res)
    {//输出一次dfs的结果
        cout<<e<<" ";
        ans.push_back(e);
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    for (auto e:ans)
    {//输出逆序存储的dfs
        cout<<e<<" ";
    }
    //判断有无全搜到
    if (res.size()!=n)
    {
        cout << "0";
    }
    
    return 0;
}
/*不想检查了
ac代码
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1010;

int n, m, s;
int sum = 0; // 经过的结点数目
vector<int> G[maxn];
bool vis[maxn] = {false}; // 是否访问过了

bool flag = false; // 调整格式
void DFS(int s)
{
   sum++;
   if (flag)
   { // 调整格式
       printf(" %d", s);
   }
   else
   {
       printf("%d", s);
       flag = true;
   }
   vis[s] = true;
   int v;
   bool hasVis;
   for (int i = 0; i < G[s].size(); i++)
   {
       v = G[s][i];
       hasVis = false;
       if (vis[v] == false)
       {
           hasVis = true;
           DFS(v);
       }
       if (hasVis) // 如果访问了这个结点的临界结点，那么一定会返回来访问他
           printf(" %d", s);
   }
}

int main()
{
   scanf("%d%d%d", &n, &m, &s);
   int u, v;
   for (int i = 0; i < m; i++)
   {
       scanf("%d%d", &u, &v);
       G[u].push_back(v);
       G[v].push_back(u);
   }
   for (int i = 1; i <= n; i++)
   { // 对结点进行排序
       sort(G[i].begin(), G[i].end());
   }
   DFS(s);
   if (sum != n)
       printf(" 0");

   return 0;
}
*/