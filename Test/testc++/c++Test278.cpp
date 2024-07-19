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
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans = a;
        ll t1 = b / 3;
        ll t2 = (b - t1 * 3 + c) / 3;
        ans += t1 + t2;
        if((b - t1 * 3 + c) %3!=0) ans++;
        if(((b-t1*3)!=0)&&((b-t1*3)+c<3)) ans = -1;
        //cout << t1 << " " << t2 << " " << (b-t1*3)+c<< " " << ans << endl;
        cout << ans << endl;
    }
    
}

int main()
{
    ios 
    Solve();
    //Codeforces Round 935 (Div. 3)_A.Setting up Camp
    return 0;
}