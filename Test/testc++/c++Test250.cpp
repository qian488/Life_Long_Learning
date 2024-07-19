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

void Binarycout(int n)
{
    int a = n % 2;
    n /= 2;
    if (n) Binarycout(n);
    cout << a;
}

void Binaryprint(int n)
{
    for (int i = 31; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int ans = 0;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (!m[x])
            {
                ans++;
                m[((1 << 31) - 1) ^ x]++;
            }
            else
            {
                m[x]--;
            }   
        }
        /*
        for(auto e:m)
        {
            cout << e.first << " " << e.second << endl;
        }
        */
        /*
        Binarycout((1 << 31) - 1);
        cout << endl;
        Binarycout(100);
        cout << endl;
        */
        cout << ans << endl;
    }
    
}

int main()
{
    ios
    solve();
    //Codeforces Round 928 (Div. 4)_D. Vlad and Division
    //按题意，需要前31位的二进制数都一样才可以放在一组
    return 0;
}