#include <iostream>
#include <string>
using namespace std;
int reverseNumber(int num) {
    // 将数字转换为字符串
    string numStr = to_string(num);

    // 如果数字为负数，则去掉负号
    bool negative = false;
    if (numStr[0] == '-') {
        numStr = numStr.substr(1);
        negative = true;
    }

    // 翻转字符串
    int start = 0;
    int end = numStr.length() - 1;
    while (start < end) {
        swap(numStr[start], numStr[end]);
        start++;
        end--;
    }

    // 将翻转后的字符串转换回数字形式
    int reversedNum = stoi(numStr);

    // 根据之前保存的负号决定是否添加负号
    if (negative) {
        reversedNum = -reversedNum;
    }

    return reversedNum;
}

int main() {
    int num;
    cin >> num;
    int reversedNum = reverseNumber(num);
    cout << reversedNum << endl;  // 输出

    return 0;
}