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
    int a, b, c;
    cin >> a >> b >> c;
    if (a+1!=c)
    {
        cout << -1 << endl;
        return;
    }
    if (a+b+c==1)
    {
        cout << 0 << endl;
        return;
    }
    int x = 1, y = 0, ans = 1;
    for (int i = 0; i < a+b; i++)
    {
        if (!x)
        {
            swap(y, x);
            ans++;
        }
        x--;
        y++;
        if (i<a)
        {
            y++;
        }
    }
    cout << ans << endl; 
}

int main()
{
    ios 
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    //Codeforces Round 937 (Div. 4)_F.0, 1, 2, Tree!
    return 0;
}