#include<iostream>

using namespace std;
//蓝桥小白赛3--蓝桥快打
//if判断太多导致混乱，其实只要向上取整就好
//小蓝是先手，只要回合数相同就能保证自己必赢的攻击力最小
typedef long long ll;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans = 1;
        /*
        for (ll i = 1; i < INF;i++)
        {
            if (a*i>=b*c)
            {
                ans = i;
                break;
            }
            
        }
        */
       if (a<=c)
        {
            ans = b;
            cout << ans << endl;
            continue;
        }
        if (a==b)
        {
            ans = c;
            cout << ans << endl;
            continue;
        }
        if ((b*c)%a==0)
        {
            ans = (b * c / a) ;
        }
        else
        {
            ans = (b * c / a) + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
/*

        ans *b >= a *c;
*/

/*AC代码
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int t;
  double a[3] = {0}; // 不用int可以在下面少一步强制类型转换
  cin >> t;
  while (t--) {
      cin >> a[0] >> a[1] >> a[2];
      cout << int(ceil(a[1] / ceil(a[0] / a[2]))) << endl; // ceil是向上取整函数
  }
  return 0;
}
*/