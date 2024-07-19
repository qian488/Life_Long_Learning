#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//字符串的全排列
//遍历交换，逐个输出
vector<string> v;
void sol(string s,int a,int b)
{
    if (a==b)
    {
        //cout << "s:" << s << " ";
        //cout << s << endl;
        v.push_back(s);
    }
    else
    {
        for (int i = a; i <= b; i++)
        {
            swap(s[a], s[i]);
            //cout << "s:" << s[a] << " " << s[i] << " ";
            sol(s, a + 1, b);
            //swap(s[a], s[i]);
        }

    }
    
}
int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    sol(s, 0, s.length() - 1);
    sort(v.begin(), v.end());
    for (auto e:v)
    {
        cout << e << endl;
    }
    
    return 0;
}