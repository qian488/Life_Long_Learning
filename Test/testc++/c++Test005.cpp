#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    float a, b, c;
    cin >> a >> b >> c;
    float p = (a + b + c) / 2;
    float area = sqrt(p * (p - a) * (p - b) * (p - c));
    // 设置输出精度为一位小数
    cout << fixed << setprecision(1);
    cout <<  area << endl;
    return 0;
}