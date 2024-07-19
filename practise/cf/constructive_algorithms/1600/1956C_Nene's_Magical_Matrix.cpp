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
    int n;
    cin >> n;
    int ans=0;
	for(int i=1;i<=n;i++) ans+=(2*i-1)*i;
	cout<<ans<<' '<<2*n<<endl;
	for(int i=n;i>=1;i--){
		cout<<"1 "<<i<<' ';
		for(int j=1;j<=n;j++) cout<<j<<' ';cout<<endl;
		cout<<"2 "<<i<<' ';
		for(int j=1;j<=n;j++) cout<<j<<' ';cout<<endl;
	}
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