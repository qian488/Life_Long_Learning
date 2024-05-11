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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k + 1), b(k + 1);
    for (int i = 1; i <= k;i++) cin >> a[i];
    for (int i = 1; i <= k;i++) cin >> b[i];
    
    while (q--)
    {
        ll d;
        cin >> d;
        int i = lower_bound(a.begin(), a.end(), d) - a.begin();
        if (a[i]==d){
            cout << b[i] << " ";
        }else{
            ll x = (d - a[i - 1]) * (b[i] - b[i - 1]) / (a[i] - a[i - 1]) + b[i - 1];
            cout << x << " ";
        }
        
    }
    cout << endl;
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