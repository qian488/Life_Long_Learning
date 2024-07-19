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
    vector<int> a(n),b;
    int tt = 0;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (int i = 1; i < n;i++){
        tt = max(a[i-1], a[i]);
        b.push_back(tt);
    }
    int ans = 1e9;
    for(auto e:b){
        ans = min(e, ans);
    }
    ans--;
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
