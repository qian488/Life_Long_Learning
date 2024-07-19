//看题解说Tarjan 缩点 + 拓扑排序 + bitset 优化状压
//不懂，先放

/*dfs
#include <iostream>

using namespace std;
//pta_dfs专场--连通数
const int N = 1e6+10;
typedef long long ll;
int h[N], e[N], ne[N], idx = 0;
bool vis[N];
int n;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int x)
{
    vis[x] = true;
    int cnt = 1;
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!vis[j])
        {
            cnt += dfs(j);
        }
    }
    return cnt;//记录结点能搜到的个数
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //加速cin和cout
    cin >> n;
    
    for (int k = 0; k < n; k++)
    {//初始化
        h[k] = -1;
        vis[k] = false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char t;
            cin>>t;
            if (t == '1')
            {//1表示有i指向j的边
                add(i, j);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {//遍历所有结点
        
        for (int k = 0; k < n; k++)
        {//重置vis
            vis[k] = false;
        }

        if (!vis[i])
        {
            ans += dfs(i);
        }
    }

    cout<<ans<<endl;

    return 0;
}
*/
/*bfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//pta_dfs专场--连通数
const int N = 1e6+10;
typedef long long ll;
int h[N], e[N], ne[N], idx = 0;
bool vis[N];
int n;
vector<int> v,w,z;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs(int x)
{
    queue<int> q;
    vis[x]=true;//表示1号点已经被遍历过
    q.push(x);
    ll cnt=0;
while(q.size())
{
    int t=q.front();
    q.pop();
    //v.push_back(t);
    //z.push_back(t);
    cnt++;

    for(int i=h[t];i!=-1;i=ne[i])
    {
        int j=e[i];
        //w.push_back(j);
        //z.push_back(j);
        //cnt++;
        if(!vis[j])
        {
            vis[j]=true;//表示点j已经被遍历过
            q.push(j);
        }
    }
    //vis[t]=false;
}
    //vis[x]=false;
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //加速cin和cout
    cin >> n;
    
    for (int k = 1; k <= n; k++)
    {//初始化
        h[k] = -1;
        vis[k] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char t;
            cin>>t;
            if (t == '1')
            {//1表示有i指向j的边
                add(i, j);
            }
        }
    }

    ll ans = 0;
    //ans=bfs(1);
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++) vis[k]=false;

        if(!vis[i]) ans+=bfs(i);
    }
    cout<<ans<<endl;
    
    for(auto e:v) cout<<e<<" ";
    cout<<endl;
    for(auto e:w) cout<<e<<" ";
    cout<<endl;
    for(auto e:z) cout<<e<<" ";
    cout<<endl;
    
    return 0;
}
*/