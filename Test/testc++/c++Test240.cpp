#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
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
int stk[N], tt = 0;
//AtCoder Beginner Contest 344_B.Delimiter
//确实有点慢啊
int main()
{
    int t;
    while(cin>>t)
    {
        stk[++tt] = t;
    }
    while(tt--)
        cout << stk[tt] << endl;
    return 0;
}