#include<iostream>
using namespace std;
//莞工集训24.01.20——D
//二维前缀和？好像可以双指针？
typedef long long ll;
const int N = 1001;
ll a[N][N], s[N][N];
int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            s[i][j]=s[i-1][j]+a[i][j];
        }
        
    }
    
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j]<k)
            {
                cnt++;
            }
            
        }
        
    }
    cout << cnt;
    return 0;
}