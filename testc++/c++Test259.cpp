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
    string s;
    cin >> s;
    vector<string>  v;
    int i = 0;
    while (i < s.length()) 
    {
        int j = i;
        while (j < s.length()) 
        {
            int p = s[j] - '0';
            if (p % 2 == 0) break;
            j++;
        }
        v.push_back(s.substr(i, j - i + 1));
        i = j + 1;
    }

    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return a.length() < b.length() || (a.length() == b.length() && a < b);
    });

    for (auto e : v) 
    {
        cout << e << endl;
    }
}

int main()
{
    ios
    Solve();
    //牛客周赛 Round 34_C小红的数字拆解
    //贪心
    return 0;
}