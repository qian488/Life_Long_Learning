#include<iostream>
#include<algorithm>
#include<string>
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
        cout << min(s, st + s) << endl;
    }

    return 0;
}