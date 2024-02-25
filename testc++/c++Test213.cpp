#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//Codeforces Round 927 (Div. 3)_E. Final Countdown
//没哦搞懂
typedef long long ll;
ll n;
string s;
vector<char> ans;
ll sol(ll i,ll c)
{
    if (i==n-1)
    {
        c += s[i] - '0';
        ans.push_back(c % 10);
        return c / 10;
    }
    ll ch = s[i] - '0';
    c += ch + sol(i + 1, c + ch);
    ans.push_back(c % 10);
    return c / 10;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        ans.clear();
        ans.push_back(sol(0, 0));
        while (ans.size()&&(ans.back()==0))
        {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        for(auto e:ans)
        {
            cout << e;
        } 
        cout << endl;
    }
    
    return 0;
}
