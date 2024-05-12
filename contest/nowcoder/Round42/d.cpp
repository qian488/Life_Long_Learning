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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 100000000
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=500005;
int T,n,m,a[N],ans,siz[N];
vector<int>q[N];
 
void dfs(int x,int fa){
    siz[x]=1;
    for(auto &u:q[x]){
        if(u==fa)continue;
        dfs(u,x);
        siz[x]+=siz[u];
    }
    if(siz[x]%2==0)ans++;
}

void Solve()
{
    int n;
    cin>>n;
    int x,y;
   for(int i=1;i<n;i++){
    cin>>x>>y;
    q[x].push_back(y);
    q[y].push_back(x);
   } 
   if(n%2){
    cout<<"-1\n";
    return;
   }
   dfs(1,0);
   cout<<ans-1<<"\n";
}
int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
