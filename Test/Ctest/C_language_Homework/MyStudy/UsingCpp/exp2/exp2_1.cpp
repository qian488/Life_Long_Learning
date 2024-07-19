#include<iostream>
#include<iomanip>
/*
程序功能：输入圆的半径，求圆的周长和面积。要求使用C++的标准输入流cin和标准输出流cout进行输入和输出。
*/
using namespace std;
#define endl "\n"
#define pi 3.14
int main()
{
    float r, c, s;
    cout << "请输入圆的半径:";
    cin >> r;
    c = 2 * pi * r;
    s = pi * r * r;
    cout << "圆的周长为：";
    cout << fixed << setprecision(2) << c << endl;
    cout << "圆的面积为：";
    cout << fixed << setprecision(2) << s << endl;
    return 0;
}