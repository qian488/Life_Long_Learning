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

ll n,k;

ll cal(ll i){
    return abs((k+(k+i-1))*i/2-(k+i+k+n-1)*(n-i)/2); 
}

void Solve()
{
    cin>>n>>k;
    int l=1, r=n;
    while (r-l>10) {
        int m1=(l+r)/2;
        int m2=(m1+r)/2;
        if (cal(m1)<cal(m2))
            r=m2;
        else
            l=m1;
    }
    ll ans = cal(l);
    for (int i = l; i <= r; i++) {
        ans = min(ans, cal(i));
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
