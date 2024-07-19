#include<iostream>
#include<cmath>
using namespace std;
//高维空间初探
int main()
{
    int n, m, s, cnt = 0;
    int a[11][11];
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        
    }
    for (int i = 0; i+1 < m; i++)
    {
        for (int j = i+1; j < m; j++)
        {
            s = 0;
            for (int k = 0; k < n; k++)
            {
                s += (a[i][k] - a[j][k]) * (a[i][k] - a[j][k]);
            }
            int d = sqrt(s);//如果是小数会转换成整型
            if (d*d==s)//再判断与原来是否相等,即可判定为整数
            {
                cnt++;
            }
            
        }
        
    }
    cout << cnt;
    return 0;
}
