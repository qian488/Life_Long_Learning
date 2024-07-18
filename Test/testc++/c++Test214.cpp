#include<iostream>

using namespace std;
//Codeforces Round 928 (Div. 4)_A. Vlad and the Best of Five
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        ll A_cnt = 0, B_cnt = 0;
        for (char c:s)
        {
            if (c=='A')
            {
                A_cnt++;
            }
            else if(c=='B')
            {
                B_cnt++;
            }
        }
        if (A_cnt>B_cnt)
        {
            cout << "A" << endl;
        }
        else
        {
            cout << "B" << endl;
        }
    }
    
    return 0;
}