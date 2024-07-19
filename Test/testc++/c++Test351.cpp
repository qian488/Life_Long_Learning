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

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return a.first < b.first;
}

void Solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    int h = 0;
    for (int i = 0; i < n;i++){
        int a, b;
        cin >> a >> b;
        h = max(h, b - a);
        ans += a;
    }
    cout << ans + h << endl;
}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    //AtCoder Beginner Contest 352_C	Standing On The Shoulders
    return 0;
}