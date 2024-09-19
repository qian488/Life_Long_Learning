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
const int N=2e5+10;
int a[N],stk[N],l[N],r[N];
void Solve(){
    int n,tt=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    // 找左边
    stk[tt]=0;
    for(int i=1;i<=n;i++){
        while(tt && a[i]>a[stk[tt]]) tt--;
        l[i]=stk[tt]+1;
        stk[++tt]=i;
    }
    // 找右边
    stk[tt=0]=n+1;
    a[n+1]=0;
    for (int i=n;i>=1;i--){
        while(tt && a[i]>a[stk[tt]]) tt--;
        r[i]=stk[tt]-1;
        if(a[r[i]+1]==a[i]) r[i] = i; // 连续右边界要保持原来的不变
        stk[++tt]=i;
    }
    ll ans=0;
    for (int i=1;i<=n;i++) ans += r[i] - l[i];
    cout << ans << endl;
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
