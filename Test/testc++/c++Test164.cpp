#include<iostream>
using namespace std;
//莞工集训24.01.20——D
//二维前缀和？好像还可以双指针？
typedef long long ll;
const int N = 1001;
ll a[N][N];
int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int y = m;
            for (int x = i; x <= n;x++)
            {
                while (j<=y&&(a[x][y]-(a[i-1][y]+a[x][j-1]-a[i-1][j-1])>k))
                {
                    y--;
                }
                if (j>y)
                {
                    break;
                }
                cnt += y - j + 1;
            }
        }
        
    }
    cout << cnt;
    return 0;
}