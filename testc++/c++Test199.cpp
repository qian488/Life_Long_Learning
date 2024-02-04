#include<iostream>
#include<set>
using namespace std;
//牛客周赛 Round 31 --小红的因子数
typedef long long ll;
set<ll> ans;
int main()
{
    ll x;
    cin >> x;
    for (ll i = 2; i <= x/i; i++)
    {
    
        while(x%i==0)
        {
            x /= i;
            ans.insert(i);
        };
        
    }
    if (x>1)
    {
        ans.insert(x);
    }
    
    cout << ans.size();
 
    return 0;
}