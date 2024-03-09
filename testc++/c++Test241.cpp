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
const int N = 1e6 + 10;
int a[N], b[N], c[N], Q[N];
set<int> sumAB;
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++) cin >> a[i];
    int m;
    for (int i = 0; i < m;i++) cin >> b[i];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            sumAB.insert(a[i] + b[j]);
        }
    }
    int l;
    for (int i = 0; i < l;i++) cin >> c[i];
    int q;
    cin >> q;
    while(q--)
    {
        bool flag = false;
        int x;
        cin >> x;
        for (int i = 0; i < l; i++)
        {
            int t = x - c[i];
            if (sumAB.count(t)>0)
            {
                flag = true;
                break;
            }
            
        }
        cout << (flag ? "Yes" : "No" )<< endl;
    }
    
}

int main()
{
    ios
    solve();
    //AtCoder Beginner Contest 344_C.A+B+C
    //不知道怎么优化
    return 0;
}