#include<iostream>
#include<set>
using namespace std;
//莞工集训24.01.27--B
//组合计数，不对，这个好像应该叫计数DP
typedef long long ll;
const int N = 1e5 + 10;
int w[101];
int dp[N];
set<int> ans;
int main()
{
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        sum += w[i];
    }
    
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int x = w[i];
        for (int j = sum; j >= x; j--) 
        {
            if (dp[j - x]) 
            {
                dp[j] = 1;
                dp[j + x] = 1;
            }
            
        }
    }

    for (int i = 1; i <= sum; i++)
    {
        if(dp[i])
        {
            ans.insert(i);
        }
    }
    cout << ans.size();
    
    /*
    for(auto e:ans)
    {
        cout << e << endl;
    }
    */
    return 0;
}