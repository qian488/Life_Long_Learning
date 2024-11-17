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
#define lowbit(x) ((x)&(-x))
const int N=2e5+10;

bool cmp(pll a, pll b) {
    return max(a.first , a.second) > max(b.second , b.first);
}


void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    if(a[0]<b[0]) swap(a,b);

    vector<pll> v(n);
    for (int i = 0; i < n; i++) v[i] = {a[i], b[i]};
    sort(v.begin(), v.end(),cmp);
    // for(auto [x,y]:v) cout<<x<<" "<<y<<endl;

    ll ans = 0;
    for (int i = 0; i < k; i++) ans += max(v[i].first, v[i].second);

    bool ok = true;
    for(int i=0;i<n;i++) ok &= (a[i]>b[i]);

    if(!ok) return cout << ans << endl,void();

    ll ksum = ans;
    ans = 0;
    for(int i=0;i<n;i++) ans=max(ans,v[i].second+ksum-v[min(i,k-1)].first);
    cout<<ans<<endl;

}

int main()
{
    ios 
    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
