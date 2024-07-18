#include<iostream>
#include<cstring>
/*
程序功能：利用C++的函数重载，编写程序，求不同类型、不同个数的数的最小值。
*/
using namespace std;

template <typename T>
T findMin(T value) {
    return value;
}

template <typename T, typename... Args>
T findMin(T value, Args... args) {
    T minRest = findMin(args...);
    return (value < minRest) ? value : minRest;
}

int main() 
{
    int intMin = findMin(1, 2, 3, 4, 5, 6, 7, 8);
    double doubleMin = findMin(3.14, 1.42, 2.34, 0.618, 4.88);
    char charMin = findMin('A', 'w', 'i', 't', 'h');
    string stringMin = findMin("this", "is", "test", "please", "ignore");

    cout << "整数的最小值为: " << intMin << endl;
    cout << "浮点数的最小值为: " << doubleMin << endl;
    cout << "字符的最小值为: " << charMin << endl;
    cout << "字符串的最小值为: " << stringMin << endl;

    return 0;
}