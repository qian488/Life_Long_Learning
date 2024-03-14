#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
//Codeforces Round 927 (Div. 3)_E. Final Countdown
//前缀和+高精度
typedef long long ll;
#define ios { ios::sync_with_stdio(0);cin.tie(0);}
int main()
{
    ios
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        vector<ll> v(n + 1);//求各位数的前缀和
        for (ll i = n - 1; i >= 0; i--)
        {
            v[i] = v[i + 1] + (s[i] - '0');
            //cout << v[i] << " ";
        }
        //cout << endl;
        string ans;
        ll t = 0;
        for (ll i = 0; i < n; i++)
        {
            t += v[i];
            //cout << t << " ";
            //cout << endl;
            ans += (char)(t % 10 + '0');
            //cout << ans << " ";
            //cout << endl;
            t /= 10;
        }
        ans += (char)(t + '0');//补上最后的进位
        while (ans.back()=='0')//去除前导0
        {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    
    return 0;
}
