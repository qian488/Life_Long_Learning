#include<iostream>
#include<algorithm>
using namespace std;
//莞工集训24.01.27--D
//模拟
//tle...
//或者可以试试记录下所有的变化区间，最后再进行排序？区间合并!
const int N = 1e5 + 10;
int a[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    
    for (int i = 0; i < m; i++)
    {
        int t, x;
        cin >> t >> x;
        if (t == 0) 
        {
            sort(a + 1, a + x + 1, [](int &x, int &y)
                 { return x > y; }); // 降序排列
        } else if (t == 1) 
        {
            sort(a + x , a + n + 1, [](int &x, int &y)
                 { return x < y; }); // 升序排列
        }

    }
    
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}