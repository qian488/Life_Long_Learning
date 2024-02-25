#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//莞工集训24.02.24--A
typedef long long ll;

int main() 
{
    string s;
    cin >> s;

    s = "0" + s;
    vector<ll> dp(s.size() + 1, 0);
    vector<ll> str(s.size());

    for (int i = 1; i < s.size(); i++) 
    {
        str[i] = s[i] - 'a' + 1;
    }

    dp[1] = str[1];
    for (int i = 2; i < s.size(); i++) 
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + str[i]);
    }

    cout << dp[s.size() - 1] << endl;

    return 0;
}