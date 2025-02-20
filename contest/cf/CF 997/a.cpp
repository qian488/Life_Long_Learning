#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    int x = a[0], y = b[0];
    ll ans = -x -y;
    for(int i=1;i<n;i++){
        x += a[i];
        y += b[i];
    }
    ans += x + y + 2*m;
    cout<<2*ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}