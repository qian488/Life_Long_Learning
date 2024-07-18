#include<iostream>
#include<set>
using namespace std;
//牛客周赛 Round 30--小红整数操作
//先暴力模拟试试，没过
//题解思路
/*
先求a,b的最小形态，即皆除以最大公约数gcd，得到
c = a/gcd(a,b)
d = b/gcd(a,b)
假定c≤d
然后就是数学中的范围收敛知识了
最小倍数l = (x + c - 1) / c
最大倍数r = y / d
然后求[l, r]的区间个数，即为答案
*/
int gcd(int a,int b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    // swap
    if (a > b) 
    {
        int t = a;
        a = b;
        b = t;
    }

    int g = gcd(a, b);
    int c = a / g;
    int d = b / g;

    // 范围组合
    int l = (x + c - 1) / c;
    int r = y / d;

    if (l <= r) 
    {
        cout << (r - l + 1) << endl;
    } 
    else 
    {
        cout << 0 << endl;
    }
    return 0;
}