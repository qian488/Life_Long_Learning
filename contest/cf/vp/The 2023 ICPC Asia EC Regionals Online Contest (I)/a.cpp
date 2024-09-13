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

map<string,bool> vis;
map<string,bool> visa;
map<string,bool> visb;

void Solve()
{
    int n,m;
    cin>>n>>m;
    vector<string> a,b;
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        if (!visa[s])
        {
            a.push_back(s);
            visa[s]=true;
        }
        
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin>>s;
        if (!visb[s])
        {
            b.push_back(s);
            visb[s]=true;
        }
    }
    
    for(int i=0;i<max(a.size(),b.size());i++){
        if(i<a.size()&&!vis[a[i]]){
            ans.push_back(a[i]);
            vis[a[i]]=true;
        }
        if(i<b.size()&&!vis[b[i]]){
            ans.push_back(b[i]);
            vis[b[i]]=true;
        }
    }
 
    for(auto e:ans){
        if(vis[e])cout<<e<<endl;
    }
}

int main()
{
    ios 
    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
