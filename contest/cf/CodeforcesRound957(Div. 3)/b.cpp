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
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k;i++)
        cin >> a[i];
    ll ans = 0;
    sort(a.begin(), a.end());
    int temp = a.back();
    a.pop_back();
    for (int i = 0; i < k - 1;i++){
        if(a[i]>=2){
            ans += a[i] - 1;
        }
        ans += a[i];
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
