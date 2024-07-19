#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;i++) cin >> v[i];
    set<int> s;
    for(auto e:v)
    {
        if(e>=1&&e<=n) s.insert(e);
    }
    if (s.size()!=n)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
        cout << 1 << " " << n + 1 << endl;
    }
    
}

int main()
{
    ios
    Solve();
    //牛客周赛 Round 34_B小红的非排列构造
    //emmm,考思维的一题
    return 0;
}