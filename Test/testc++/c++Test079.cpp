#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//组最大数
bool cmp(string &a,string &b)
{
    return (a + b) > (b + a);
}
int main()
{
    int n;
    while (cin>>n)
    {
        cin.ignore();
        string s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        sort(s, s + n, cmp);
        for (int i = 0; i < n; i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
    
    return 0;
}