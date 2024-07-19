#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//字符串排序
//不明白为什么第二个测试点过不了
vector<string> str;
bool cmp(string s1,string s2)
{
    return s1.length() < s2.length();
}
int main()
{
    int n;
    while (cin>>n)
    {
        cin.ignore();
        string s;
        for (int i = 0; i < n; i++)
        {
            getline(cin, s);
            if (s=="stop")
            {
                n = i;
                //break;
            }
            str.push_back(s);
        }

        sort(str.begin(), str.end(), cmp);

        for (int i = 0; i < n; i++)
        {
            cout << str[i] << endl;
        }
        
        /*
        for (const auto& s : str)
        {
            cout << s << endl;
        }
        */
        str.clear();
    }
    
    return 0;
}