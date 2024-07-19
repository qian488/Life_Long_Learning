#include<iostream>

using namespace std;
//牛客周赛 Round 30--小红的删字符
//模拟
int main()
{
    string s;
    cin >> s;
    s = s.substr(0, 1) + s.substr(2, 1);
    cout << s;
    return 0;
}