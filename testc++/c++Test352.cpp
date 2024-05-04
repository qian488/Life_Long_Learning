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
    int n, k;
    cin >> n >> k;
    map<int, int> a;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        a[x] = i;
    }
    set<int> s;
    for (int i = 1; i <= k;i++) s.insert(a[i]);
    int ans = *s.rbegin() - *s.begin();
    for (int i = k+1; i <= n;i++){
        s.erase(a[i - k]);
        s.insert(a[i]);
        int t = *s.rbegin() - *s.begin();
        ans = min(ans, t);
    }
    cout << ans << endl;
}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    //AtCoder Beginner Contest 352_D	Permutation Subsequence
    return 0;
}