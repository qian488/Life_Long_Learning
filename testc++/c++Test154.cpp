#include<iostream>
#include<algorithm>
using namespace std;
//牛客周赛 Round 28--小红的统计区间(easy)
/*
小红拿到了一个数组，她想知道，有多少非空区间满足区间所有元素之和不小于k？
第一行输入两个正整数n,k，用空格隔开。
第二行输入n个正整数a i，代表数组的元素。
输入
5 5
1 4 2 1 3
输出
8
以为是前缀和，但是具体应该是滑窗，计数窗口之和大于等于k,即是答案
*/
typedef long long ll;
const int N = 1e5 + 10;
ll a[N], s[N];
int main()
{
    ll n, k;
    cin >> n >> k;
    //输入数组，维护前缀和
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    ll ans = 0;
    //滑动窗口
    for (int i = 1, j = 0; i <= n; i++)
    {//j是左边界，i是右边界，当区间[j,i]之和大于等于k时，计数
        while (j<=i&&s[i]-s[j]>=k)
        {
            j++;
        }
        ans += j;//累计每次的计数
    }
    cout << ans;
    return 0;
}