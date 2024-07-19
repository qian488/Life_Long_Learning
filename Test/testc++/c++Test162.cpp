#include<iostream>
#include<algorithm>
using namespace std;
//莞工集训24.01.20——B
//模拟
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll ans = max(i * 2 - 2, (n - i + 1) * 2 - 2);
        cout << ans << endl;
    }
    return 0;
}