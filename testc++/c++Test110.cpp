#include <iostream>
#include <map>
using namespace std;
// 字符串处理
map<string, string> m;

int main()
{
    string s;
    while (getline(cin, s))
    {
        if (s.empty())
        {
            break; // 词典读取完毕，跳出循环
        }

        int pos = s.find(" ");
        string a = s.substr(0, pos);
        string b = s.substr(pos + 1);
        m[b] = a; // 注意这里交换了外语单词和英文单词的位置
    }

    string c;
    bool flag = true; // 判断是否为第一个输出

    while (cin>>c)
    {
        if (c.empty())
        {
            break; // 外语单词读取完毕，跳出循环
        }

        if (m.count(c) > 0)
        {
            if (flag)
            {
                cout << m[c];
                flag = false;
            }
            else
            {
                cout << endl << m[c];
            }
        }
        else
        {
            if (flag)
            {
                cout << "eh";
                flag = false;
            }
            else
            {
                cout << endl << "eh";
            }
        }
    }

    return 0;
}