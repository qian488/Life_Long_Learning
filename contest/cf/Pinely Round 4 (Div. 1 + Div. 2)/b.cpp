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
#define INF (ll)2e18
#define MOD 100000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n;
    cin >> n;
    vector<ll> b(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> b[i];
    }

    vector<ll> a(n);
    bool ok = true;

    a[0] = b[0];
    for (int i = 1; i < n-1; i++) {
        a[i] = b[i-1] | b[i];
        if ((a[i-1] & a[i]) != b[i-1]) {
            ok = false;
            break;
        }
    }
    a[n-1] = b[n-2];
    if ((a[n-2] & a[n-1]) != b[n-2]) ok = false;

    if (ok) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
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
