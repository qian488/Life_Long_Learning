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
#define ios {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N=1e6+10;

vector<int> a[N];
bool vis[N];
int sum;

void dfs(int u){
    if(!vis[u]){
        sum++;
        vis[u]=1;
        for(auto e:a[u]){
            if(!vis[e]) dfs(e);
        }
    }
}

void Solve(){
    int n;
    cin>>n;

    for(int i=0;i<=n;i++){
        a[i].clear();
        vis[i]=0;
    }
    sum=0;

    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        l--;
        a[l].push_back(r);
        a[r].push_back(l);
    }

    dfs(0);
    cout<<((sum==n+1)?1:0)<<endl;
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
