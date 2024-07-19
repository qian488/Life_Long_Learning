#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=1e6+10;

void Solve()
{
    string s;
    cin >> s;
    int num1 = 0, num0 = 0;
    for(char c:s)
    {
        if (c=='1')
        {
            num1++;
        }
        else
        {
            num0++;
        }
    }
    int ans = max(0, num1 - num0);

    int t = 0;
    for(char c:s)
    {
        if (c=='0')
        {
            num0--;
        }
        else
        {
            num1--;
            t++;
        }
        ans = max(ans, num1 - num0 + (t > 0 ? 1 : 0));
    }

    cout << ans << endl;
}

int main()
{
    ios
    Solve();
    //牛客周赛 Round 33——C小红的 01 串
    /*思路: 枚举
其实只能删除第1/第2，只能保证删除数组的前面一个区间，最多保留一个
题外话
如果题目改成第1/第2/.../第k，那最大价值数组是多少？
其实也是类似的思路*/
    return 0;
}