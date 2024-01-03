#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string s1 = " hello,world! ";
    string s2 = " hello,Awith! ";
    string s3 = " li jia kai nb ";
    vector<string> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    string str;
    for (auto e:v)
    {
        str += e;
    }
    cout << "str1:" << str << endl;

    vector<string> vt = v;
    str.clear();
    for (auto e:vt)
    {
        reverse(e.begin(), e.end());
        str += e;
    }
    cout << "str2:" << str << endl;

    str.clear();
    reverse(vt.begin(), vt.end());
    for (auto e:vt)
    {
        reverse(e.begin(), e.end());
        str += e;
    }
    cout << "str3:" << str << endl;
    return 0;
}