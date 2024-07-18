#include<iostream>
#include<map>
using namespace std;
//统计英语单词个数
map<string, int> m;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        while (n--)
        {
            string s;
            cin >> s;
            m[s]++;
        }
        for(auto e:m)
        {
            cout << e.first << " " << e.second << endl;
        }
        m.clear();
    }
    
    return 0;
}