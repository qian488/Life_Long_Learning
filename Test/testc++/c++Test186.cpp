#include<iostream>

using namespace std;
//蓝桥第 4 场 小白入门赛--乘飞机
typedef long long ll;
const int N = 1e5 + 10;
int a[N];
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        bool flag=false;
        for (int i = l; i < r; i++) 
        {
            for (int j = i + 1; j <= r; j++)
            {
                if (abs(a[j] - a[i]) <= 365) 
                {
                    flag = true;
                    break;
                }
            }
            if (flag) 
            {
              break;
            }
        }
        
        if (flag)
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