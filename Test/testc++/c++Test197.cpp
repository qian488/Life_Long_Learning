#include<iostream>

using namespace std;
//莞工集训24.02.03--G
typedef long long ll;
const int N = 2e5 + 10;
char letter[27] = {
    'k', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};
int main()
{
    string s, ans;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (i+1<s.size())
        {
            int t = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (t<=26)
            {
                ans += letter[t];
                i++;
            }
            else
            {
                ans += letter[s[i] - '0'];
            }
        }
        else
        {
            ans += letter[s[i] - '0'];
        }
    }
    
    cout << ans;
    return 0;
}
/*
#include<iostream>

using namespace std;
//莞工集训24.02.03--G
typedef long long ll;
const int N = 2e5 + 10;
int main()
{
    string s, ans;
    cin >> s;
    int num=(s[0] - '0') * 10 + (s[1] - '0');
    for (int i = 0; i + 1 < s.size(); i++)
    {
        num=(s[i] - '0') * 10 + (s[i+1] - '0');
        if (num<=26)
        {
            i++;
        }
        else
        {
            num = s[i] - '0';
        }
        char letter = num + 'A' - 1;
        ans += letter;
    }
    cout << ans;
    return 0;
}
*/