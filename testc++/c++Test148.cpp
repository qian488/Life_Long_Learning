#include<iostream>

using namespace std;
//蓝桥小白赛3--蓝桥快打
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