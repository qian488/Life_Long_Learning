#include<iostream>

using namespace std;
//牛客周赛 Round 28 --小红的好数组
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e9 + 10;
int main()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    for (ll i = 0; i < n-1; i++)
    {
        ans = (ans * k) % mod;
    }
    
    cout << ans;
    return 0;
}