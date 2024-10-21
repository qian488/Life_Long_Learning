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

void Solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> vis(n + 1,0); 

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    bool ok = false;

	queue<int> q;
    q.push(1),vis[1]=1;
	while(q.size()){
		int x=q.front();
        q.pop();
		for(auto y:g[x]){
			if(y==1){
                ok = true;
                cout<<vis[x]<<endl;
                return;
            }
            if(!vis[y]){ 
                vis[y]=vis[x]+1;
                q.push(y);
            }
		}
    }
    if(!ok) cout<<-1<<endl;
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
