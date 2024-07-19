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

void Solve()
{
    int n,sz;
	ll x,y,ans=0;
	vector<ll> a[4];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		if((x+y)%2==0){
			a[0].push_back(x+y);
			a[1].push_back(x-y);
		}else{
			a[2].push_back(x+y);
			a[3].push_back(x-y);
		}
	}
	for(int i=0;i<4;i++){
		sort(a[i].begin(),a[i].end());
		sz=a[i].size();
		for(int j=0;j<sz;j++) ans+=a[i][j]*(2*j+1-sz);
	}
	cout<<(ans/2)<<endl;
}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    //AtCoder Beginner Contest 351_E	Jump Distance Sum
    return 0;
}