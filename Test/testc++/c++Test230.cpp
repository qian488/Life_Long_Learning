#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
//Codeforces Round 931 (Div. 2)_B.Yet Another Coin Problem
//打表+找规律
typedef long long ll;
int ans[] = {0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        if (n<15)
        {
            cout << ans[n] << endl;
        }
        else if(n%15==5)
        {//(n/15-1+2)
            cout << n / 15 + 1 << endl;
        }
        else if(n%15==8)
        {//(n/15-1+3)
            cout << n / 15 + 2 << endl;
        }
        else
        {
            cout << n / 15 + ans[n % 15] << endl;
        }
    }
    return 0;
}

/*
int m[5] = {15, 10, 6, 3, 1};
const int N = 1e7 + 10;
int dp[N];
//这样dp会超时或者爆空间
int main() 
{
    int t;
    cin >> t;

    dp[0] = 0;
    for (int i = 1; i <= N; i++) 
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < 5; j++) 
        {
            if (m[j] <= i && dp[i - m[j]] + 1 < dp[i]) 
            {
                dp[i] = dp[i - m[j]] + 1;
            }
        }
    }

    while (t--) 
    {
        int n;
        cin >> n;

        cout << dp[n] << endl;
    }

    return 0;
}
*/

/*贪心...好像不对,12会处理不了而出错
int m[5] = {15, 10, 6, 3, 1};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        ll cnt = 0;
        for (int i = 0; i < 5;i++)
        {
            if (n/m[i]>0)
            {
                cnt += n / m[i];
                n -= cnt * m[i];
            }
    
            cout << cnt << endl;
            if(n<=0){break;}
        }
        if(n==2){cnt+=2;}
        cout << cnt << endl;
    }
    return 0;
}
*/