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
    string s;
    cin >> s;
    int n = s.length() - 1;
    bool flag = true;
    for (int i = 1; i < n;i++) if (s[i]!='=') flag = false;
    if (s[0] != '<' || s[n] != '>') flag = false;
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main()
{
    ios 
    Solve();
    //AtCoder Beginner Contest 345_A.Leftrightarrow
    return 0;
}