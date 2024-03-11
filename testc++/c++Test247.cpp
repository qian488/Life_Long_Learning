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
const int N = 101;
int a[N], b[N];
void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n;i++) cin >> a[i];
        for (int i = 0; i < m;i++) cin >> b[i];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i]+b[j]<=k)
                {
                    ans++;
                }
                
            }
            
        }
        cout << ans << endl;
    }
    
}

int main()
{
    ios
    solve();
    //Codeforces Round 933 (Div. 3)
    
    return 0;
}