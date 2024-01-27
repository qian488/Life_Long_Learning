#include<iostream>
using namespace std;
//莞工集训24.01.20——G
//组合计数?
typedef long long ll;
const ll mod = 1000000007;
const int N=101;
ll dp[N][N][N];
int main() 
{
    ll n,m;
    cin >> n >> m;

    dp[0][0][0] = 1;
    
    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= m; j++) 
        {
            
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}