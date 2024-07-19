#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
//Codeforces Round 930 (Div. 2)_A.Shuffle Party
typedef long long ll;

/*
这段代码通过位运算的技巧，将输入的 n 转换为一个二进制数，
其最高位及其左边的位都被填充为1，而其余位都保持不变。
然后，通过将结果加1并右移一位，得到小于等于 n 的最大的2的幂次方。
*/
int f(int n)
{
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);
    return (n + 1) >> 1;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll ans=f(n);
        cout << ans << endl;
    }
    return 0;
}