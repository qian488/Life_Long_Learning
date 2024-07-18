#include<bits/stdc++.h>
//蓝桥第 9 场 小白入门赛——盖印章
using namespace std;

typedef long long ll;
#define endl "\n"
const int N = 1e6 + 10;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a, b;
    char g[n][m];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if(g[i][j]=='1')
                cnt++;
        }
        
    }
    cout << cnt - 2 * k << " " << 3 * k - cnt;
    /*
    a = cnt / 3;
    b = (cnt - a * 3) / 2;
    if(a+b==k) cout << a << " " << b << endl;
    b = cnt / 2;
    a = (cnt - b * 2) / 3;
    if(a+b==k) cout << a << " " << b << endl;
    */
    return 0;
}