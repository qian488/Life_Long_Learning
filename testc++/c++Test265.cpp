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
    unordered_set<string> ans;
    //11个测试点
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            swap(s[i], s[j]);
            string t = s;
            //cout << t << endl;
            ans.insert(t);
            swap(s[i], s[j]);
        }
        
    }
    cout << ans.size() << endl;
    
   /*11个测试点
    int n = s.length() - 1;
    unordered_set<string> ans;
    ans.reserve(n * (n + 1) / 2);

    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            string t = s;
            swap(t[i], t[j]);
            ans.insert(t);
        }
    }

    cout << ans.size() << endl;
    */
}

int main()
{
    ios 
    Solve();
    //AtCoder Beginner Contest 345_C.One Time Swap
    return 0;
}