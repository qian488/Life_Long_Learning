#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void solve()
{
    ll x;
    cin >> x;
    
    ll f = 1;
    ll n = 1;

    while (f < x) {
        n++;
        f *= n;
    }

    cout << n << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}