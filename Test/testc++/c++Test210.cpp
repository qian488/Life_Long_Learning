#include<iostream>

using namespace std;
//Codeforces Round 927 (Div. 3)_A. Thorns and Coins
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int cnt = 0;
        for (int i = 0; i < s.length();i++)
        {
            if(s[i]=='@')cnt++;
            if(s[i]=='*'&&s[i+1]=='*')break;
        }
        cout << cnt << endl;
    }
    
    return 0;
}