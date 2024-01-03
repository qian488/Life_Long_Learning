#include<iostream>
#include<map>
using namespace std;
//气球升起来
map<string, int> m;

int main()
{
    int n;
    while (cin>>n)
    {
        int max = 0;
        string ans = "";
        cin.ignore();
        while (n--)
        {
            string s;
            cin >> s;
            m[s]++;
            if (m[s]>max||(m[s]==max&&s<ans))
            {
                max = m[s];
                ans = s;
            }
            
        }
        cout << ans << endl;
        m.clear();
    }
    
    return 0;
}