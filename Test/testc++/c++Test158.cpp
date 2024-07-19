#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
//牛客小白月赛86--水平考试
/*
纠结了半天什么情况下会有5分的情况，最后发现，要么0分，要么10分
*/
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int len1 = s1.length(), len2 = s2.length();
        set<char> s, f;
        for (int i = 0; i < len1;i++)
        {
            s.insert(s1[i]);
        }    
        for (int i = 0; i < len2; i++)
        {
            f.insert(s2[i]);
        }
        bool t = includes(f.begin(), f.end(), s.begin(), s.end());
        if (s==f||t)
        {
            cout << 10 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        
    }
    
    return 0;
}