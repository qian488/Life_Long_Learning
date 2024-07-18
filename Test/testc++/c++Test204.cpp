#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//莞工集训24.02.17--G
int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }

    vector<int> dp(N, 1);

    for (int i = 0; i < N; i++) 
    {
        for (int j = max(0, i - K); j < i; j++) 
        {
            if (A[j] <= A[i]) 
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = *max_element(dp.begin(), dp.end());

    cout << ans << endl;
    return 0;
}