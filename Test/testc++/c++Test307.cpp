#include<bits/stdc++.h>
//蓝桥第 9 场 小白入门赛——字典树考试
using namespace std;

typedef long long ll;
#define endl "\n"
const int N=2e5+10;
ll cnt[32];
int main()
{
    int n;
    cin>>n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin>>a;
        for (int k = 0; k < 32; k++)
        {
            int t = ((a >> k) & 1);
            //cout << ((tt >> k) & 1) << " ";
            cnt[k] += t;
        }

    }
    for(int k = 0; k < 32; k++)
    {
        if (cnt[k] >= 2) ans += (cnt[k] - 1) * cnt[k] / 2;
    }
    cout << ans << endl;

    return 0;
}