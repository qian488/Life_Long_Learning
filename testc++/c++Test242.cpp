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
vector<string> v;
void solve()
{
    string t, ans = "";
    cin >> t;
    int n;
    cin >> n;
    int cnt = 0;
    while (n--)
    {
        int m;
        cin >> m;
        for (int i = 0; i < m;i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }

    }
    
}

int main()
{
    ios
    solve();
    //AtCoder Beginner Contest 344_D.String Bags
    //string背包？
    //DP
    return 0;
}