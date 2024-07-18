#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//牛客周赛 Round 28--小红的字符串
vector<string> v;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n-1; i++)
    {
        string st = s.substr(i, 2);
        v.push_back(st);
    }
    sort(v.begin(), v.end());
    for (auto e:v)
    {
        cout << e << endl;
    }
    
    return 0;
}