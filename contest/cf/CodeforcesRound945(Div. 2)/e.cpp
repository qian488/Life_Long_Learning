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
    ll n;
    cin>>n;
    vector<ll> a(n + 1);
    ll maxn = 0, minn = n + 1;
    set<ll> se;
    for (ll i = 1; i <= n;i++){
        cin >> a[i];
        if (a[i]!=i){
            minn = min(minn, i);
            maxn = max(maxn, i);
            se.insert(i + a[i]);
        }
    }
    cout << "=========================" << endl;
    cout << maxn << " " << minn << endl;
    cout << "=========================" << endl;
    for(auto e:se)
        cout << e << " ";
    cout << endl;
    cout << "=========================" << endl;
    ll ans = 0;
    if (se.empty()){
        ans = n * (2 * n + 1);
        //for (int i = 1; i <= 2 * n;i++) ans += i;
        cout << ans << endl;
        return;
    }
    for (ll i = maxn + 1; i <= 2 * n; i++){
        ll tt = min(i - 1, minn + n);
        cout << tt << endl;
        ans += tt;
    }
    if(se.size()==1) ans++;
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
