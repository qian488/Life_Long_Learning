#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//莞工集训24.02.03--A
typedef long long ll;
bool check1(string s)
{
    string st = s;
    reverse(s.begin(), s.end());
    return s == st;
}
bool check2(string s)
{
    return s.substr(0, 2) == s.substr(6, 2) && s.substr(2, 2) == s.substr(4, 2);
}
int main()
{
    string s,ans1,ans2;
    cin >> s;
    int y = stoi(s.substr(0, 4));
    int m = stoi(s.substr(4, 2));
    int d = stoi(s.substr(6, 2));
    
    cout << y << " " << m << " " << d << endl;

    cout << check1(s) << endl;
    cout << check2(s) << endl;
    return 0;
}