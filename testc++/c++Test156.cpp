#include<iostream>
#include<algorithm>
using namespace std;
//牛客周赛 Round 28--小红的统计区间(hard)
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
hard版本存在负数，不能滑窗
输入
4 5
2 -100 5 6
输出
3
题解给出的方法是离散化+树状数组
又是树状数组，想想怎么去做
*/
typedef long long ll;
const int N = 1e5 + 10;
ll a[N];
int main()
{
    ll n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        
    }
    ll ans = 0;
    
    cout << ans;
    return 0;
}