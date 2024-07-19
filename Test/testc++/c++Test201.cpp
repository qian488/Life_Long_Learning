#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
//莞工集训24.02.17--A
typedef long long ll;
map<int, int> m[10];
int main()
{
    int n = 10;
    char s[2];
    cin >> s;
    int a = 1189, b = 841;
    for (int i = 0; i < n; i++)
    {
        m[i].insert(make_pair(a,b));

        if (a>b)
        {
            a /= 2;
        }
        else
        {
            b /= 2;
        }
    }
    for(auto p:m[s[1]-'0'])
    {
        auto t1 = max(p.first, p.second);
        auto t2 = min(p.first, p.second);
        cout << t1 << endl;
        cout << t2 << endl;
    }
    return 0;
}