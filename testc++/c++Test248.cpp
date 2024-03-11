#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N = 2e5 + 10;
int a[N];
void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n;i++) cin >> a[i];
        bool flag = ture;
        int c[3] = {-1, -2, -1};
        
            if (flag)
            {
                cout << "YES" << endl;
            }
            else
            {
                coout << "NO" << endl;
            }
    }
    
}

int main()
{
    ios
    solve();
    //Codeforces Round 933 (Div. 3)
    //有点怪
    return 0;
}