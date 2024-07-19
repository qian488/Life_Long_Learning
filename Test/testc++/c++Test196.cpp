#include<iostream>

using namespace std;
//莞工集训24.02.03--F
int main()
{
    string s;
    cin >> s;
    int a_cnt = 0, A_cnt = 0, n_cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]>='a'&&s[i]<='z')
        {
            a_cnt++;
        }
        if (s[i]>='A'&&s[i]<='Z')
        {
            A_cnt++;
        }
        if (s[i]>='0'&&s[i]<='9')
        {
            n_cnt++;
        }
        
    }
    cout << A_cnt << endl;
    cout << a_cnt << endl;
    cout << n_cnt << endl;
    return 0;
}