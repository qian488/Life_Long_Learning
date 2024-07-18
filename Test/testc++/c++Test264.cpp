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
    ll X;
    cin >> X;
    //9个测试点
    //ll ans = (ll)ceil(a/10);
    //cout << ans << endl;
    //15个测试点
    /*
    ll t = (a + 9) / 10;
    cout << t << endl;
    */
    //ac
    ll result = X / 10;
    if (X > 0 && X % 10 != 0) result += 1;
    cout << result << endl;
}

int main()
{
    ios 
    Solve();
    //AtCoder Beginner Contest 345_B.Integer Division Returns
    return 0;
}