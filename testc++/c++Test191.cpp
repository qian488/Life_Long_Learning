#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
//牛客周赛 Round 30--小红构造回文
//模拟，因为原本就是回文，故将第一个与s[0]不等的字母对进行交换就是一个新的回文串
//还有部分测试点没过，abcba
map<char, int> m;
int main()
{
    string s;
    cin >> s;
    bool flag = true;
    for(char c:s)
    {
        m[c]++;
    }

    for(auto e:m)
    {
        if (e.second==1)
        {
            flag = false;
        }
        
    }

    int pos = 1;
    for (int i = 1; i < s.size();i++)
    {
        if (s[i]!=s[0])
        {
            pos = i;
            break;
        }
        
    }
    int endpos = s.size() - 1;
    if (flag)
    {
        swap(s[0], s[pos]);
        swap(s[endpos], s[endpos-pos]);
        cout << s;
    }
    else
    {
        cout << -1;
    }
    return 0;
}