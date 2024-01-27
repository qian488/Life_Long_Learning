#include<iostream>

using namespace std;
//牛客小白月赛86--数组段数
const int N = 1e6 + 10;
int a[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        int cnt = 0;
        for (int i = l, j = 1; i <= r; i++)
        {
            
            while (j<=i&&a[i]==a[j])
            {
                j++;
            }
            cnt += j;
        }
        int ans = r - l + 1 - cnt;
        cout << ans << endl;
    }
    
    return 0;
}