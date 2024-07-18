#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=1e6+10;


void Solve()
{
    int n;
    cin>>n;
    ll sum = 0, maxn = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        sum += x;
        maxn = max(maxn, x);
    }
    ll tt = sum - maxn;
    ll ans=0;
    if (maxn>tt)
    {
        ans = 2 * tt;
    }
    else if(maxn<=tt)
    {
        if (sum%2==1)
        {
            ans = sum - 1;
        }
        else
        {
            ans = sum;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios 
    Solve();
    //莞工天梯赛预选赛_J.梅易天每一天都喝每益添
    return 0;
}