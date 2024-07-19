#include <iostream>

using namespace std;
//abb
//后缀和
long long cnt[100010][26];
int main() 
{
    long long n, res = 0;
    string s;
    cin >> n >> s;
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            cnt[i][j] = cnt[i + 1][j];
        }
        cnt[i][s[i] - 'a']++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (j!=s[i]-'a')
            {
                res += cnt[i + 1][j] * (cnt[i + 1][j] - 1) / 2;
            }
            
        }
        
    }
    cout << res;
    return 0;
}
