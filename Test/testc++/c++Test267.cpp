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
        int n, k;
        cin >> n >> k;
        map<int, int> ma;
        map<int, int> mb;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n;i++)
        {
            cin >> a[i];
            ma[a[i]]++;
        }
        for (int i = 0; i < n;i++) 
        {
            cin >> b[i];
            mb[b[i]]++;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<int> l, r;

        for (int i = 0; i < 2 * k; i++)
        {
            cout << l[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 2*k; i++)
        {
            cout << r[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios 
    Solve();
    //Codeforces Round 934 (Div. 2)_B.Equal XOR
    return 0;
}