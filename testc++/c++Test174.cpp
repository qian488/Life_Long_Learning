#include<iostream>

using namespace std;
//牛客周赛 Round 29--小红的小小红
//还是模拟
int main()
{
    string s;
    cin >> s;

    int xiao_pos = s.find("xiao");

    string t = s.erase(xiao_pos,4);
    int hong_pos = t.find("hong");
    string r = t.erase(hong_pos,4);

    string res = "xiaohong" + r;

    cout << res << endl;

    return 0;
}