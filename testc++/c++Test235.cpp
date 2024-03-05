#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
//Codeforces Round 932 (Div. 2)_A.Entertainment in MAC
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        string st = s;
        reverse(st.begin(), st.end());
        int len = s.size();
        if (s[0]>s[len-1])
        {
            cout << st << s << endl;
        }
        else
        {
            cout << s << endl;
        }
    }

    return 0;
}