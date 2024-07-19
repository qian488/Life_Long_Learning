#include<iostream>

using namespace std;
//牛客小白月赛86--数组段数
//前缀和
/*
判断截取的子数组有几段即可
防止TLE，可用前缀和
首先标记每一段的开头部分
再用前缀和表示每一个位置及其以前的段数
最后通过相减即可
*/
typedef long long ll;
const int N = 1e6 + 10;
int a[N], s[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i]!=a[i-1]) s[i]=1;//标记每一段的开头位置
        s[i] += s[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        int ans = s[r] - s[l] + 1;
        cout << ans << endl;
    }
    
    return 0;
}