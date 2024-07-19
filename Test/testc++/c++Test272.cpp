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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> l(m+1), r(m+1);
    for (int i = 1; i <= m;i++)
    {
        cin >> l[i] >> r[i]; 
    }
    string s="R";
    string st;
    cin >> st;
    s += st;
    int t = 1, pos = 0;
    for(char ch:s)
    {
        if (ch=='L'&&pos>1) pos--;
        if (ch=='R'&&pos<n) pos++;
        while (t<m+1&&(pos<l[t]||pos>r[t])) t++;
    }
    if (t==m+1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << t << endl;
    }
}

int main()
{
    ios 
    Solve();
    //莞工天梯赛预选赛_H.往下往下往下
    return 0;
}