#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
typedef long long ll;
using namespace std;

//聪明的质检员
//坑点：开ll，ans初始化一个很大的数
const int N = 1000010;
ll n, m, s, Y, sum, ans = 0x3f3f3f3f3f3f3f3f;
int w[N], v[N], L[N], R[N];
ll a[N], b[N];
bool check(int mid)
{
    Y = 0, sum = 0;
    //memset(a,0,sizeof(a));
	//memset(b,0,sizeof(b));
    //cout << a[1] << " " << b[1] << endl;
    for (int i = 1; i <= n; i++)
    {
        if(w[i]>=mid)
        {
            a[i] = a[i - 1] + 1;
            b[i] = b[i - 1] + v[i];
        }
        else
        {
            a[i] = a[i - 1];
            b[i] = b[i - 1];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        Y += (a[R[i]] - a[L[i] - 1]) * (b[R[i]] - b[L[i] - 1]);
    }
    //cout << "Y:" << Y << " s:" << s << endl;
    sum = abs(Y - s);
    //cout << sum << endl;

    return Y > s;
}
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> L[i] >> R[i];
    }

    int l = - 1, r = 1e9 + 1;
    while (l+1<r)
    {
        int mid = (l + r) >> 1;
        //cout << "mid:" << mid << endl;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
        if (sum<ans)
        {
            ans = sum;
        }
    }
    
    cout << ans;

    return 0;
}