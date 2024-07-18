#include<iostream>
using namespace std;
//莞工集训24.01.20——E
//组合计数？
//运气好试出来的...
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e7 + 10;
ll dp[N];
int main()
{
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;

    for (int i = 4; i <= n; i++) 
    {
        dp[i] = (2 * dp[i - 1] % mod + dp[i - 3] % mod) % mod;
    }

    cout << dp[n] << endl;
    return 0;
}