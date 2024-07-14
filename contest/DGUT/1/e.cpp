#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        if(i<=4){
            dp[i] = dp[i - 1];
        }else{
            dp[i] = (dp[i - 1] + dp[i - 5]) % MOD;
        }
    }
    
    cout << dp[n] << endl;
    return 0;
}