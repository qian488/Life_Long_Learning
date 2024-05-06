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
/*树形DP
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N=1e5+10;

int n,l,r;
int ans;
char str[N];
int a[N];
vector<int> son[N];
vector<int> tr;

int dfs(int idx){
    int res=1;
    for(auto t:son[idx]) res+=dfs(t);
    return res;
}

void dfss(int idx,int num,int& temp){
    if(temp*2-1>num) a[idx]=1;
    if(temp*2-1<num) a[idx]=-1;
    temp--;
    for(auto t:son[idx]) dfss(t,num,temp);
}

int main(){
    cin>>n>>l>>r>>(str+1);
    if(str[1]=='R') tr.push_back(1);
    for(int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        if(str[b]=='R') tr.push_back(b);
        else son[a].push_back(b);
    }
    
    for(auto f:tr){
        int m=1;
        for(auto t:son[f]) {
            m+=dfs(t);
        }
        
        ans+=(m/2)*2;
        
        int mm=m;
        dfss(f,m,mm);
    }
    
    if(tr[0]!=1) {
        int t=dfs(1);
        int tt=N*2;
        ans+=t;
        dfss(1,t,tt);
    }
    
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    
    return 0;
}
*/
/*并查集
#include<bits/stdc++.h>
#define endl '\n'

typedef long long  ll; 
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;
 
int n,l,r;
int s[100005];
int a[100005];
int p1[100005];
int p2[100005];
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
		if(sum[i]){
			if(b[i]){
				p1[i]=p2[i]=sum[i]/2;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int root=s[i];
		if(b[root]){
			if(p1[root]){
				cout<<1<<' ';
				p1[root]--;
			}else if(p2[root]){
				cout<<-1<<' ';
				p2[root]--;
			}else{
				cout<<0<<' ';
			}
		}else{
			cout<<1<<' ';
		}
	}
    
	return 0;
}
*/