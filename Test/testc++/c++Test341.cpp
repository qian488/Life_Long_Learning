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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll ed = a.back(), cnt = 1;
    a.pop_back();
    while (!a.empty()&&ed==a.back()){
        a.pop_back();
        cnt++;
    }
    while (!a.empty()){
        ll kk = a.back() - ed;
        if(k<kk*cnt) break;
        k -= kk * cnt;
        ed = a.back();
        while (!a.empty()&&ed==a.back()){
            a.pop_back();
            cnt++;
        }
    }
    ed += k / cnt;
    k %= cnt;
    cnt -= k;
    ll ans = ed * n - cnt + 1;
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