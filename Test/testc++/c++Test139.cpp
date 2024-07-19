#include<iostream>

using namespace std;
//pta数论专场--炒鸡楼梯
//列举前几项发现是斐波那契数列
//一直等待评测，无法验证结果是不是
int f(int x)
{
    if (x==1||x==2)
    {
        return 1;
    }
    else
    {
        return f(x-1)+f(x-2);
    }
    
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        cout << f(m) << endl;
    }
    
    return 0;
}