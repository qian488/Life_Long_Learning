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

void Solve()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        vis[i] = true;
        int t = v[i];
        
    }
    

    int ans = INF;
}

int main()
{
    ios
    Solve();
    //牛客周赛 Round 33——D小红的数组清空
    //贪心
    //暴搜也行
    return 0;
}