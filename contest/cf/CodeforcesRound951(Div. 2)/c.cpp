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

int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

int find_lcm(const vector<int>& arr) {
    int res = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        res = lcm(res, arr[i]);
    }
    return res;
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int kk = find_lcm(a);
    vector<ll> v(n, 0);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        v[i] = kk / a[i];
        if (v[i] > 1000000000) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "-1\n";
    } else {
        ll tt = 0;
        for (int i = 0; i < n; ++i) {
            tt += v[i];
        }
        if (tt < kk) {
            for (auto e : v) {
                cout << e << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }
    }
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
