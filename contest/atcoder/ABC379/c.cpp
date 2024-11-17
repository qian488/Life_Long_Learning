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
#include<numeric>
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
    ll n,m;
    cin>>n>>m;
    vector<ll> x(m),a(m);
    for(int i=0;i<m;i++) cin>>x[i];
    for(int i=0;i<m;i++) cin>>a[i];

    vector<pll> mp;
    for (int i = 0; i < m; i++) {
        mp.push_back({x[i], a[i]});
    }
    sort(mp.begin(), mp.end());

    ll ans = n*(n+1)/2, sum = 0;
    for(int i=0;i<m;i++){
        if(sum < mp[i].first - 1) return cout<<-1<<endl,void();

        sum += mp[i].second;
        ans -= mp[i].first*mp[i].second;
    }

    if(sum != n) return cout<<-1<<endl,void();

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
