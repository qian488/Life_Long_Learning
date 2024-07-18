#include<iostream>

using namespace std;
//牛客周赛 Round 29--小红的白日梦
//模拟
const int N = 1e5 + 10;

int main()
{
    int n;
    cin >> n;
    string a, e;
    cin >> a >> e;
    for (int i = 0; i < n; i++)
    {
        if (a[i]=='N'&&e[i]=='Y')
        {
            a[i] = 'Y';
            e[i] = 'N';
        }
        
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]=='Y')
        {
            cnt += 2;
        }
        if(e[i]=='Y')
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}