#include<iostream>
#include<iomanip>
/*
程序功能：输入长方形的长和宽，求长方形的周长和面积。要求使用C++的标准输入流cin和标准输出流cout进行输入和输出。
*/
using namespace std;
#define endl "\n"

int main()
{
    float a, b, c, s;
    cout << "请输入长方形的长和宽（前者为长，后者为宽）：";
    cin >> a >> b;
    c = 2 * a + 2 * b;
    s = a * b;
    cout << "该长方形的周长为：" << fixed << setprecision(2) << c << endl;
    cout << "该长方形的面积为：" << fixed << setprecision(2) << s << endl;
    return 0;
}