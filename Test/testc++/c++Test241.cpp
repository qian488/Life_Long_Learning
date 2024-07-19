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
set<int> sumABC;
void solve()
{
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m;i++) cin >> b[i];
    int l;
    cin >> l;
    vector<int> c(l);
    for (int i = 0; i < l;i++) cin >> c[i];

    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            for (int k = 0; k < l; k++)
            {
                sumABC.insert(a[i] + b[j] + c[k]);
            }
        }
    }
    
    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        if(sumABC.find(x)!=sumABC.end())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    
}

int main()
{
    ios
    solve();
    //AtCoder Beginner Contest 344_C.A+B+C
    //不知道怎么优化,不知道为什么出不来结果,感觉没毛病
    //我傻逼了，输入都忘了。。。
    return 0;
}