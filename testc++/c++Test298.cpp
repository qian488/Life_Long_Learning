#include <iostream>
#include <cmath>
using namespace std;
//蓝桥杯——01串的熵
//实际上套公式枚举就好
int main()
{
    int n = 23333333;
    for (int i = 1; i < n / 2; ++i)
    {
        double a = i * 1.0 / n;  // 0出现的占比
        double b = (n - i) * 1.0 / n;  // 1出现的占比
        double res = 0;
        res -= a * log2(a) * i + b * log2(b) * (n - i);
        if (fabs(res - 11625907.5798) < 0.0001)
        {
            cout << i << endl;
            break;
        } 
    }
    return 0;
}