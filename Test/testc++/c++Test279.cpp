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
    int T;
    cin >> T;
    while (T--)
    {
        ll a, b, m;
        cin >> a >> b >> m;
        ll ans = 0;
        ans = m / a + m / b + 2;
        /*
        if(a==b) ans = 2 * (m + 1) / a;
        if(abs(a-b)==1) ans = (m + 1) / a + 1 + (m + 1) / b + 1;
        if(abs(a-b)>1) ans = 2;//发射间隔超过一分钟的是什么情况
        */
        cout << ans << endl;
    }
    
}

int main()
{
    ios 
    Solve();
    //Codeforces Round 935 (Div. 3)_B.Fireworks
    return 0;
}