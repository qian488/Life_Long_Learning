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

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n;i++) cin >> a[i];
    for (int i = 0; i < n + 1;i++) cin >> b[i];
    ll ans = 1e9;
    for (int i = 0; i < n;i++){
        ans = min((int)ans, abs(a[i] - b[n]));
        ans = min((int)ans, abs(b[i] - b[n]));
        if(min(a[i],b[i])<=b[n]&&b[n]<=max(a[i],b[i])) ans = 0;
    }
    for (int i = 0; i < n; i++){
        ans += abs(a[i] - b[i]);
    }
    ans += 1;
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
