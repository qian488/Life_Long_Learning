#include<iostream>
using namespace std;
//莞工集训24.01.20——G
//DP
typedef long long ll;
const ll mod = 1000000007;
const int N=101;
ll dp[N][N][N] = {0, 0, 1};
int main() 
{
    ll n,m;
    cin >> n >> m;
    
    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= m; j++) 
        {
            for (int k = 0; k <= m; k++)
            {
                if (i&&k%2==0)
                {
                    dp[i][j][k] = dp[i - 1][j][k / 2];
                }
                if (j)
                {
                    dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k + 1]) % mod;
                }
                
            }
            
        }
    }

    cout << dp[n][m-1][1] << endl;

    return 0;
}