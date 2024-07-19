#include<iostream>
/*
程序功能：从键盘输入图形的行数和列数，在屏幕上输出相应的图形。要求使用C++的标准输入流cin和标准输出流cout进行输入和输出。
*/
using namespace std;

void printPattern(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() 
{
    int rows, cols;

    cout << "请输入图形的行数: ";
    cin >> rows;

    cout << "请输入图形的列数: ";
    cin >> cols;

    cout << "输出图形如下：" << endl;
    printPattern(rows, cols);

    return 0;
}