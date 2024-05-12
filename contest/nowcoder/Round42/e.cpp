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
ll ans[1005],a[1005][1005]={1};
void Solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        a[i][0]=1;
        for(int j=1;j<=i;j++)a[i][j]=(a[i-1][j-1]+a[i-1][j])%MOD;
        a[i][i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=k;j>=1;j--){
            ans[j]=(ans[j]+ans[j-1]*10%MOD+(s[i]-'0')*a[i-1][j-1]%MOD)%MOD;
        }
    }
    cout<<ans[k]<<endl;
    
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
