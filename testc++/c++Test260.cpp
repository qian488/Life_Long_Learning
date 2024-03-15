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

string StringBuilding(int n)
{
    if (n%2==1) return "";
    else if(n==2) return "AA";
    else if(n%2==0)
    {
        string p = "AABB";
        string tt = p;
        while (tt.length()<n) tt += p;
        return tt.substr(0, n);
    }
}

void Solve()
{
    int n;
    cin >> n;
    string ans = StringBuilding(n);
    if(!ans.empty())
    {
        cout << "YES" << endl;
        cout << ans << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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
    //
    return 0;
}