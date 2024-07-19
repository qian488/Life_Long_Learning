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
#define MOD 100000000
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n;
    cin>>n;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n;i++){
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), [&](pair<ll, ll> i, pair<ll, ll> j)
         { return i.first < j.first; });
    ll ans = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        int kk = min(v[l].second, v[r].second);
        ans += kk * (v[r].first - v[l].first);
        v[l].second -= kk;
        v[r].second -= kk;
        if (!v[l].second) l++;
        if (!v[r].second) r--;
    }
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
