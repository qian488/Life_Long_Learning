#include<iostream>
#include<string>
#include<vector>
using namespace std;
//qls学习字符串
int main()
{
    //输入
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);

    //数字变空格，全部变小写
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            s[i] = ' ';
        }
        s[i] = tolower(s[i]);
    }

    //清除重复空格
    //vector<string> v;
    //首尾插入空格，以免一些特殊的数据
    s.insert(0, " ");
    s.insert(s.length(), " ");
    string str = "";
    bool isSpace = false;
    for(auto c:s)
    {
        if (c==' ')
        {
            if (!isSpace)
            {
                str += c;
                isSpace = true;
            }
            
        }
        else
        {
            str += c;
            isSpace = false;
        }
        
    }
    //清除标点符号前的空格
    for (int i = 0; i < str.size(); i++)
    {
        if ((i>0)&&(str[i]==','||str[i]=='.'||str[i]=='\'')&&(str[i-1]==' '))
        {
            str.erase(i - 1, 1);
        }
        
    }
    //清除在首尾加入的空格
    int firstSpacePos = str.find_first_of(' ');
    str.erase(firstSpacePos, 1);
    int lastSpacePos = str.find_last_of(' ');
    str.erase(lastSpacePos, 1);
    //cout << str << endl;
    //v.push_back(str);

    while (n--)
    {
        string a, b;
        getline(cin, a);
        getline(cin, b);

        //在str中找到a,替换成b
        int len = str.length();
        while (str.find(a)<len)
        {
            str.replace(str.find(a), a.length(), b);
            len = str.length();
        }
        
        /*
        好像格式有点问题
        for (int i = 0; i < v.size(); i++)
        {
            int pos = 0;
            while ((pos = v[i].find(a, pos)) != string::npos)
            {
                v[i].replace(pos, a.length(), b);
                pos += b.length();
            }
        }

        for(auto e:v)
        {
            cout<<e<<" ";
        }
        */

        cout << str << endl;
    }
    

    return 0;
}
