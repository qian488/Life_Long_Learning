#include<iostream>
#include<algorithm>
#include<set>
#include<string>
using namespace std;
//题目统计
set<string> s;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string t;
            cin >> t;
            transform(t.begin(), t.end(), t.begin(), ::tolower);
            s.insert(t);
        }
        cout << s.size() << endl;
        s.clear();
    }
    
    return 0;
}