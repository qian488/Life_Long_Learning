#include<iostream>

using namespace std;
//莞工集训24.01.20——A
//模拟
typedef long long ll;
int main()
{
    ll a, b, n;
    cin >> a >> b >> n;
    ll s = a * 5 + b * 2;
    ll w = n / s;
    n -= w * s;
    ll d = w * 7;
    for (int i = 0; i < 5;i++)
    {
        if (n > 0) 
        {
            n -= a;
            d++;
        }
    }
    for (int i = 0; i < 2; i++) 
    {
        if (n > 0) 
        {
            n -= b;
            d++;
        }
    }
    cout << d;
    return 0;
}