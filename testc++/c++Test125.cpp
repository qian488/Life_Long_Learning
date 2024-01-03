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
vector<int> tt;//用于存储邻接点时，在遍历邻接点之前对其进行排序，实现搜索的时候按从小到大的编号搜索
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