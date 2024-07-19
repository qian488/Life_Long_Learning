#include<iostream>
#include<string>
using namespace std;
//S属性大爆发
int main()
{
    int n;
    cin >> n;
    string line;
    for (int i = 0; i < n; i++)
    {
        cin >> line;
        int t=0;
        // line.find('S')<line.size()||line.find('s')<line.size()
        if ((t=line.find('s',t) != string::npos) || (t=line.find('S',t) != string::npos))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    
    }
    
    return 0;
}