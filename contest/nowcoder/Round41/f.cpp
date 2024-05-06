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
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

//树形DP
void Solve()
{
    
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
/*
#include <bits/stdc++.h>

typedef long long LL;

const int N = 1e5 + 10;
std::vector<int> g[N];
bool vis[N];
int col[N];
std::vector<int> vec[N];
int l, r;

void dfs(int u, int fa) {
    vec[u].push_back(u);
    col[u] = r >= std::abs(l) ? r : l;
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        if (vec[u].size() < vec[v].size()) {
            std::swap(vec[u], vec[v]);
        }
        for (auto &c : vec[v]) {
            vec[u].push_back(c);
        }
        vec[v].clear();
    }

    if (vis[u]) {
        int len = vec[u].size();
        int ul = 0, ur = len - 1;
        int sum = 0;
        while (ul < ur) {
            sum += -l;
            col[vec[u][ul++]] = l;
            while (sum >= r && ul <= ur) {
                sum -= r;
                col[vec[u][ur--]] = r;
            }
        }
        if (ul == ur) col[vec[u][ul]] = sum;
        else if (sum) {
            col[vec[u][ul - 1]] += sum;
        }
        vec[u].clear();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n >> l >> r;

    std::string s;
    std::cin >> s;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'R') vis[i] = true;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        std::cout << col[i] << " \n"[i == n];
    }

    return 0;
}
*/

/*
#include<bits/stdc++.h>
#define endl '\n'

typedef long long  ll; 
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;
 
ll n,l,r;
int s[100005];
ll p[100005];
int sum[100005];
bool b[100005];

void init(){
	for(int i=1;i<=n;i++){
		s[i]=i;
	}
	return;
}
int find(int x){
	int root=s[x];
	if(root!=x){
		s[x]=find(root);	
	}
	return s[x];
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
    //cout<<setiosflags(ios::fixed)<<setprecision(1);
    
    cin>>n>>l>>r;
    ll maxn=min(abs(l),abs(r));
    init();
    int f,c;
    char ch;
    for(int i=1;i<=n;i++){
    	cin>>ch;
    	if(ch=='R'){
    		b[i]=true;
		}
	}
	for(int i=1;i<n;i++){
		cin>>f>>c;
		if(!b[c])
			s[c]=f;
	}
	for(int i=1;i<=n;i++){
		find(i);
		sum[s[i]]++;
	}

	for(int i=1;i<=n;i++){
		int root=find(i);
		if(b[root]){
			sum[root]--;
			if(sum[root]==0){
				cout<<-p[root]<<' ';
				p[root]=0;
			}else{
				if(abs(l)>abs(r)){
					if(p[root]+l+r*sum[root]>0){
						cout<<l<<' ';
						p[root]+=l;
					}else{
						cout<<r<<' ';
						p[root]+=r;
					}
				}else{
					if(p[root]+r+l*sum[root]<0){
						cout<<r<<' ';
						p[root]+=r;
					}else{
						cout<<l<<' ';
						p[root]+=l;
					}
				}
			}
		}else{
			if(abs(l)>abs(r)){
				cout<<l<<' ';
			}else{
				cout<<r<<' ';
			}
		}
	}
    
	return 0;
}
*/