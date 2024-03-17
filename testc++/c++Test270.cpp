#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=1e5+10;
int h[N],e[N],ne[N],idx;
bool vis[N];
int g[N];
int n;
//添加一条边a->b
void insert(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u)
{

    vis[u]=true;//vis[u]表示点u已经被遍历过
    //点u就是被搜到的点
    for(int i=h[u];i!=-1;i=ne[i])
    {//遍历邻接表
        int j=e[i];
        if(!vis[j]) dfs(j);//没搜过的结点就继续dfs
    }
    
}

void Solve()
{
    cin >> n;
    //初始化
    idx=0;
    memset(h,-1,sizeof h);
    memset(vis, false, sizeof vis);

    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
        insert(i, g[i]);
    }
    dfs(1);
    if (vis[n])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    ios 
    Solve();
    //莞工天梯赛预选赛_F.天蓝色的彼岸
    return 0;
}