#include<iostream>
#include<cmath>
using namespace std;
//Codeforces Round 932 (Div. 2)_D.Exam in MAC
//不太懂，先放.
typedef long long ll;
const int N = 1e5 + 10;
int s[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,c;
        cin >> n >> c;
        
        for (int i = 1; i <= n;i++)
        {
            cin >> s[i];
        }

        
    }

    return 0;
}
/*题解代码
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve_case() {
    int n, c;
    cin >> n >> c;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int odd = 0, even = 0;
    ll ans = 1ll * (c + 1) * (c + 2) / 2;
    for (int i = 0; i < n; i++) {
        ans -= s[i] / 2 + 1;
        ans -= c - s[i] + 1;
        if (s[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    ans += 1ll * even * (even + 1) / 2;
    ans += 1ll * odd * (odd + 1) / 2;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve_case();
    }
}
*/