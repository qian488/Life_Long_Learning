#include<iostream>

using namespace std;
//pta数论专场--哥德巴赫最新猜想
/*
数论的题重思路，在这里补充一下
题目要求输出一个数最少是多少个素数之和
由哥德巴赫猜想可知，一个不小于6的偶数，都是两个素数之和。故只要是偶数的结果就是2个
然后我们可以分析出还剩下奇数，奇数要怎么判断？
很容易可以联想素数本身，如果是素数，那最小就是1个
顺着下去思考
如果一个奇数减去2，还是素数的话，说明结果就是2个，2和这个素数
如果不是素数，那结果就是3个
为什么想要减2？
除2以外，所有素数都是奇数，两个奇数之和可以获得一个偶数，再加上一个素数还是奇数
即一个奇数可以拆为一奇一偶，只要先拆出个奇数是素数，对应的偶数可以拆为两个素数，故总数为3
*/
typedef long long ll;
bool is_prime(ll x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        ll t;
        cin >> t;
        if (is_prime(t))
        {
            cout << 1 << endl;
        }
        else if(is_prime(t-2)||t%2==0)
        {
            cout << 2 << endl;
        }
        else
        {
            cout<< 3 << endl;
        }
    }
    return 0;
}