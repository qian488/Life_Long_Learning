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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    ll ans = 0;
    map<pii, int> mp1, mp2, mp3;
    map<vector<int>, int> cnt;
    for (int i = 0; i+2 < n; i++)
    {
        ans += mp1[{a[i], a[i + 1]}]++;
        ans += mp2[{a[i], a[i + 2]}]++;
        ans += mp3[{a[i + 1], a[i + 2]}]++;
        vector<int> v = {a[i], a[i + 1], a[i + 2]};
        ans -= cnt[v] * 3;
        cnt[v]++;
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
