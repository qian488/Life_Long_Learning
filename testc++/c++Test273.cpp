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
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n;i++) cin >> a[i];
    int ans, last;
    vector<int> tt;
    int j = 1;
    for (int i = 1; i <= n;i++)
    {
        if (a[i]==j)
        {
            tt.push_back(i);
            j++;
        } 
    }
    /*
    if (tt.size())
    {
        for(auto e:tt)
        cout << e << " ";
    }
    cout << endl;
    */
    ans = n - tt.size();
    if (ans==n)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}

int main()
{
    ios 
    Solve();
    //莞工天梯赛预选赛_K.砖头情结
    return 0;
}