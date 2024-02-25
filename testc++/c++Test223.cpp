#include<iostream>
#include<map>
using namespace std;
//HUAWEI Programming Contest 2024（AtCoder Beginner Contest 342_C.Many Replacement
map<char, char> m;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char c = 'a'; c <= 'z';c++)
    {
        m[c] = c;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char a, b;
        cin >> a >> b;
        for(auto& e:m)
        {
            if (e.second==a)
            {
                e.second = b;
            }
            
        }
    }
    for(char c:s)
    {
        cout << m[c];
    }
    return 0;
}
