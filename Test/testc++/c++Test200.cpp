#include<iostream>
#include<algorithm>
using namespace std;
//牛客周赛 Round 31 --小红的字符串中值
//还是超时,只能过33%
/*题解
思路: 枚举
对于i个字符，如果其为目标字符
则可提供的奇数子字符串数位：
min(i+1,n - i)
不过，为什么呢？
*/
typedef long long ll;
int main()
{
    int n;
    char chr;
    cin >> n >> chr;
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i]==chr)
        {
            ll d = min(i, n - i - 1) + 1;
            ans += d;
        }
        
    }
    
    cout << ans;
    return 0;
}