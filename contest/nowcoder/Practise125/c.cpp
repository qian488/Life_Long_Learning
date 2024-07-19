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
#define MOD 100000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;
const ll inf=1e17;
void Solve()
{
    ll y;
    cin>>y;
    ll ans=0;
    for(int i=0;i<10;i++){
        for(int j=1;j<10;j++){
            for(ll k=1;k<inf;k*=10){
                ll tt=y-j*k-i;
                if(tt>=0&&tt%11==0&&k>tt/11) ans++;
            }
        }
    }
    
    cout<<ans<<endl;
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
