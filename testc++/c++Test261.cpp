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
    vector<int> v;
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    bool flag = true;
    vector<int> ans;
    int pos = -1;
    for (int i = 0; i < n-1;i++) if (v[i]>v[i+1]) pos = i;
    for (int i = 0; i <= pos;i++)
    {
        if (v[i]>9)
        {
            ans.push_back(v[i] / 10);
            ans.push_back(v[i] % 10);
        }
        else ans.push_back(v[i]);
    }
    for (int i = pos+1; i < n;i++) ans.push_back(v[i]);
    for (int i = 1; i < ans.size();i++)
    {
        if(ans[i]<ans[i-1]) 
        {
            flag = false;
            break;
        }
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    ios 
    int t;
    cin >> t;
    while(t--)
    {
        Solve();
    }
    
    //Educational Codeforces Round 163 (Rated for Div. 2)_B.Array Fix
    return 0;
}