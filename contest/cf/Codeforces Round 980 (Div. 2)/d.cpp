#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<string>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

struct Dij{
    const ll inf=1e18;
    Dij(){}
    vector<ll>dis;
    vector<bool>vis;
    vector<vector<pii>>e;
    int n;
    Dij(int _n){
        n=_n;
        dis.assign(n+1,inf);
        vis.assign(n+1,false);
        e.resize(n+1);
    }
    void dij(int u){
        priority_queue<pii,vector<pii>,greater<pii> >q;
        q.push({0,u});
        dis[u]=0;
        while(q.size()){
            auto [d,now]=q.top();
            q.pop();
            if(dis[now]<d)continue;
            for(auto [v,w]:e[now]){
                if(dis[v]>dis[now]+w){
                    dis[v]=dis[now]+w;
                    q.push({dis[v],v});
                }
            }
        }
    }
    void print(){
        for(int i=1;i<=n;i++)cout<<dis[i]<<' ';cout<<'\n';
    }
};

// 最短路解法

void Solve()
{
    int n;
    cin>>n;
    vector<ll>a(n+1);
    vector<int>b(n+1);
    vector<ll>pre(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    ll ans=0;
    Dij dj=Dij(n);
    for(int i=1;i<=n;i++){
        dj.e[i].push_back({b[i],a[i]});
    }
    for(int i=1;i<n;i++){
        dj.e[i+1].push_back({i,0});
    }
    dj.dij(1);
    for(int i=1;i<=n;i++){
        ans=max(ans,pre[i]-dj.dis[i]);
    }
    cout<<ans<<'\n';
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
