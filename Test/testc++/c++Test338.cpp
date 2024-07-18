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
ll n, k;
ll a[N];
ll res;
bool check(ll mid){
    ll y = k;
    for(int i=0;i<n;i++){
		if(a[i]<mid) y-=(mid-a[i]);
	}
    if(y>=0) res = y;
    return y >= 0 ? true : false;
}

void Solve()
{
    cin >> n >> k;
    for (int i = 0; i < n;i++) cin >> a[i];
    sort(a, a + n);
    ll ans = 0;
    ll l = 0, r = a[n - 1] + k;
    while(l+1<r){
        ll mid = (l + r) / 2;
        if (check(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    ll cnt = 0;
    for (int i = 0; i < n;i++){ 
        if(a[i]<=l) cnt++;
    }
    ans = n * l - (cnt - 1 - res);
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
    
    //Codeforces Round 942 (Div. 2)_C	Permutation Counting
    return 0;
}