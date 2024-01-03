#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
//列出连通集
/*
给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N−1编号。
进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。
*/
//部分正确，有个测试点没过
const int N = 100010, M = N * 2;
int h[N],e[M],ne[M],idx;// 对于每个点k，开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
bool vis[N];//用于判断是否搜过
queue<int> q;//队列，用于bfs
vector<int> res;
vector<int> tt;//用于存储邻接点时，在遍历邻接点之前对其进行排序，实现搜索的时候按从小到大的编号搜索

void add(int a,int b)
{//邻接表存图
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u)
{
    vis[u]=true;//表示该点已被搜
    res.push_back(u);//存入答案数组

    tt.clear();
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
}

void bfs(int v)
{
    vis[v]=true;
    q.push(v);//标记该点被搜，并入队

    while(q.size())
    {//队列不空就一直循环
        int t=q.front();
        q.pop();//取出顶点
        res.push_back(t);//存入答案数组

        tt.clear();
        for(int i=h[t];i!=-1;i=ne[i])
        {//遍历邻接表
            int j=e[i];
            tt.push_back(j);//存储所有邻接点
        }
        sort(tt.begin(),tt.end());//在遍历邻接点之前对其进行排序，实现搜索的时候按从小到大的编号搜索
        for(auto j:tt)
        {//遍历邻接点，没搜过的结点就入队
            if(!vis[j])
            {
                vis[j]=true;
                q.push(j);
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    //初始化
    memset(h,-1,sizeof h);
    memset(vis,0,sizeof vis);

    for(int i=0;i<m;i++)
    {//将图存入邻接表
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }

    //dfs
    for (int i = 0; i < n;i++)
    {//遍历顶点
        if (!vis[i])
        {//没搜过的话，进入搜索
            res.clear();
            dfs(i);
            //输出搜索的结果
            cout << "{ ";
            for(auto elem:res)
            {
                cout<<elem<<" ";
            }
            cout << "}" << endl;
        }
        
        
    }
        
    memset(vis,0,sizeof vis);
    //bfs
    for (int i = 0; i < n; i++)
    {//遍历顶点
        if (!vis[i])
        {//没搜过的话，进入搜索
            res.clear();
            bfs(i);
            //输出搜索的结果
            cout << "{ ";
            for(auto elem:res)
            {
                cout<<elem<<" ";
            }
            cout << "}" << endl;
        }
        
    }

    return 0;
}