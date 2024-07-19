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

void Solve()
{
    int a[7],c[7]={0,1,5,10,50,100,500};
	int i,q,x;
	for(i=1;i<=6;i++) cin>>a[i];
	cin>>q;
	while(q--){
		cin>>x;
		for(i=6;i>=1;i--)
		{
			while(x>=c[i]&&a[i]>0) x-=c[i],a[i]--;
		}
		if(x>0){
			cout<<"No";
			return ;
		}
	}
	cout<<"Yes";
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
