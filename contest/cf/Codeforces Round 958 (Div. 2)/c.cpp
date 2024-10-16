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
#define MOD 100000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    ll n;
    cin >> n;

    vector<ll> v;

    for (int i = 62; i >= 0; i--)
    {
        ll x = 1LL << i;
        if ((x & n) == x && x != n) v.push_back(n - x);
    }
    v.push_back(n);

    cout << v.size() << endl;
    for (auto e : v){
        cout << e << " ";
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
