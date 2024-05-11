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
#define MOD 998244353
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;
ll c0[N],c1[N],s0[N],s1[N],sum[N];
void Solve()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        c0[i]=c0[i-1];//0的个数
        c1[i]=c1[i-1];//1的个数
        s0[i]=s0[i-1];
        s1[i]=s1[i-1];
        if(s[i]=='0'){
            sum[i]=sum[i-1]+c1[i]*i-s1[i];
            c0[i]++;
            s0[i]+=i;
        }else if(s[i]=='1'){
            sum[i]=sum[i-1]+c0[i]*i-s0[i];
            c1[i]++;
            s1[i]+=i;
        }
        s0[i]%=MOD;s1[i]%=MOD;
        sum[i]=(sum[i]%MOD+MOD)%MOD;
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        ll ans=sum[r]-sum[l-1];
        ans=ans-(c0[l-1]*(s1[r]-s1[l-1])-(c1[r]-c1[l-1])*s0[l-1])%MOD;
        ans=ans-(c1[l-1]*(s0[r]-s0[l-1])-(c0[r]-c0[l-1])*s1[l-1])%MOD;
        ans=(ans%MOD+MOD)%MOD;
        cout<<ans<<endl;
    }
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