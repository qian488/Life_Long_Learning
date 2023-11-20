#include<iostream>
#include<iomanip>
using namespace std;
//歌唱比赛评委打分

int main()
{
    int n, m, t;
    cin >> n >> m;
    int maxs = 0, maxn = 0, minn = 11, sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0, maxn = 0, minn = 11;
        for (int j = 0; j < m; j++)
        {
            cin >> t;
            maxn = max(maxn, t);
            minn = min(minn, t);
            sum += t;
            //cout << "sum:" << sum << " ";
        }
        ans = sum - maxn - minn;
        //cout << "ans:" << ans << " ";
        maxs = max(maxs, ans);
        //cout << "maxs:" << maxs << " ";
    }
    cout << fixed << setprecision(2) << maxs*1.0 / (m - 2);
    return 0;
}