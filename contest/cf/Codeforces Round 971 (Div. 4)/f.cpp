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
    ll n,q;
    cin>>n>>q;
    vector<ll>a(n+1),s(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    auto cal=[&](ll x)->ll{
        if(x==0)return 0;
        ll ans=0,k=(x-1)/n;
        ans+=k*s[n];
        //那当前是第k+1个散段
        //第k个散段会分成[k,n][1,k]
        x-=k*n;
        if(k==0)ans+=s[x];
        else{
            int l1=k+1,r1=n;
            int l2=1,r2=k;
            if(x>=r1-l1+1){
                ans+=s[r1]-s[l1-1];
                x-=(r1-l1+1);
                ans+=s[l2+x-1]-s[l2-1];
            }else{
                ans+=s[l1+x-1]-s[l1-1];
            }
        }
        return ans;
    };
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<cal(r)-cal(l-1)<<endl;
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
