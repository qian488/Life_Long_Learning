#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string str1, str2;

    cin >> str1;
    //清除输入流中的换行符，确保getline正常输入
    cin.ignore();
    getline(cin, str2);

    // 在str1，str2前后插入空格
    str1.insert(0, " ");
    str1.insert(str1.length(), " ");
    str2.insert(0, " ");
    str2.insert(str2.length(), " ");
    
    int count = 0, pos = -1;
    //全部转换成小写，方便查找
    transform(str1.begin(), str1.end(), str1.begin(),::tolower);
    transform(str2.begin(), str2.end(), str2.begin(),::tolower);

    cout << str1 << "\n" << str2 << endl;

    if (str2.find(str1) == string::npos)
    {
        cout << -1;
    }
    else
    {
        int t = 0;
        while ((t = str2.find(str1, t)) != string::npos)//判断是否在str2中找到str1
        {
            count++;//循环计数

            if (pos == -1)//记录第一次的位置
            {
                pos = t;
            }

            //t += str1.length();
            t += 1;
        }
        cout << count << " ";
        cout << pos;
    }
    return 0;
}