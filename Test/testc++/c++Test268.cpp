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
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        map<int, int> m;
        vector<int> a(n);
        for (int i = 0; i < n;i++) 
        {
            cin >> a[i];
            m[a[i]]++;
        }
        //sort(a.begin(), a.end());
        int ans, last;
        vector<int> tt;
        for (int i = 0; i <= n + 1; i++)
        {
            if(m[i]==0) 
            {
                last = i;
                break;
            }
            else if(m[i]==1)
            {
                tt.push_back(i);
            }
        }
        if(tt.size()>1) ans = tt[1];
        else ans = last;
         
        cout << ans << endl;
        
    }
    
}

int main()
{
    ios 
    Solve();
    //Codeforces Round 934 (Div. 2)_C.MEX Game 1
    return 0;
}