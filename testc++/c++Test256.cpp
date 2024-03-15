#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
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
const int N=1e6+10;
bool vis[N];
vector<int> v;

void dfs(int k,int t)
{
    while (v[k]==t)
    {
        if (!vis[k])//如果没进入过，将其标记
        {
            vis[k] = true;
            int p = lower_bound(v.begin(), v.end(), t + 1) - v.begin();//在数组 v 中查找第一个大于 t+1 的元素，得到位置 p
            dfs(p, t + 1);//继续dfs查找分段
            break;//直到搜完所有连续分段后，退出
        }
        k++;
    }
    
}

void Solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {//遍历vis[N]查看没被标记的有多少个，就是答案
        if (vis[i])//如果被搜过的就跳过
        {
            continue;
        }
        vis[i] = true;
        int t = v[i];
        ans++;
        int k = lower_bound(v.begin(), v.end(), t + 1) - v.begin();//在数组 v 中查找第一个大于 t+1 的元素，得到位置 k
        dfs(k, t + 1);//进入dfs接着看k往后能连续多远，以及能够分成多少段
    }
    cout << ans << endl;
}

int main()
{
    ios
    Solve();
    //牛客周赛 Round 33——D小红的数组清空
    //贪心
    //暴搜也行
    //尽可能少的代价，就是说尽可能去一次清理连续的数
    return 0;
}