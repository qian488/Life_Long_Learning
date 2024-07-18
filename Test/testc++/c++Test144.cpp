#include<iostream>

using namespace std;
//牛客练习赛120--生成函数
//ax+by+cz=m?暴力做肯定超时，DP?
//好像不对啊，ax+by+cz+m=ai+bj+ck
//不对，好像应该是ax+bx+cx+m=ay+by+cy
//不对啊，这不还是ax+by+cz=m?或者说可以是ax + by + cz ≡ m (mod t),线性同余方程，扩展欧几里得法？
/*
将这个问题转化为一个线性同余方程，即判断是否存在整数解(x, y, z)，使得ax + by + cz ≡ m (mod t)，其中t为砝码质量a、b、c的最大公约数。
为什么可以这样转化呢？
我们观察一下天平的平衡条件：
左边砝码质量的和必须等于右边砝码质量的和，即ax + by + cz = m。
而左边和右边的砝码质量和都是t的倍数，因为a、b、c都是t的倍数。
所以我们可以将等式两边同时除以t，得到ax/t + by/t + cz/t = m/t，
进一步化简得到ax' + by' + cz' = m/t，其中x' = x/t，y' = y/t，z' = z/t。
因此，我们只需要判断m/t是否为整数，如果是整数，则存在整数解(x', y', z')，使得ax' + by' + cz' = m/t，也就是存在一种放置砝码的方式使得天平平衡。
如果m/t不是整数，则不存在整数解，天平无法平衡。
*/
//原来这叫裴蜀定理
typedef long long ll;
int gcd(int x,int y)
{
    return y ? gcd(y, x % y) : x;
}

void sol()
{
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    int t = gcd(gcd(a, b), c);
    if (m%t==0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        sol();
    }
    return 0;
}