#include<iostream>
#include<algorithm>
using namespace std;
//火烧赤壁
typedef long long ll;
const int N = 20010;
ll a[N], b[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    ll x = 0, l, r, p_l = -99999999, p_r = -9999999;
    for (int i = 1; i <= n; i++)
    {
        l = a[i], r = b[i];
        //cout << "a[i]:" << a[i] << " b[i]:" << b[i] << endl;
        
        if(l>p_r)
        {
            x += r - l;
        }
        else
        {
            x -= p_r - l;
            x += r - l;
        }

        p_l = l, p_r = r;
        //cout << "x:" << x << endl;
    }
    cout << x;
    return 0;
}