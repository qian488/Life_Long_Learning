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
    int n,m;
    cin>>n>>m;
    vector<int> x(m),a(m);
    for(int i=0;i<m;i++) cin>>x[i];
    for(int i=0;i<m;i++) cin>>a[i];

    vector<pll> mp;
    for (int i = 0; i < m; i++) {
        mp.push_back({x[i], a[i]});
    }
    sort(mp.begin(), mp.end());

    ll ans = 0;
    ll _pos = 1; 

    for (int i=0;i + 1<mp.size();i++) {
        ll pos = mp[i+1].first;
        ll count = mp[i].second;
        ll cnt = pos - _pos;
        if(cnt<count) return cout<<-1<<endl,void();
        _pos=pos;
        ans+=cnt*(cnt+1)/2;
        mp[i+1].second += count - cnt;
        cout<<ans<<" ";
    }

    ll count = mp.back().second;
    ans+=count*(count-1)/2;

    cout << ans << endl;
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
