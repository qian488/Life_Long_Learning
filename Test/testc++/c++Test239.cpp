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
//AtCoder Beginner Contest 344_A.Spoiler
//脑抽了。。。
int main()
{
    string s, ans = "";
    cin >> s;
    int l = s.find('|');
    int r = s.find('|', l + 1);
    ans += s.substr(0, l) + s.substr(r+1);
    cout << ans;
    return 0;
}