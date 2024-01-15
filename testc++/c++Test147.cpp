#include<iostream>
#include<algorithm>
using namespace std;
//蓝桥小白赛3--聪明的交换策略
int main()
{
    int cnt = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i] - '0';
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i]>a[j])
        {
            swap(a[i], a[j]);
            cnt++;
        }
        }
        
    }
    cout << cnt << endl;
    for (auto e : a)
    {
        cout << e;
    }
    return 0;
}