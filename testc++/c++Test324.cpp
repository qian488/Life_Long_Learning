#include<iostream>
#include<iomanip>
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
const int N=2e5+10;

void Solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int mn = 0;
    int mx = 0;
    int cur = 0;

    for (char c : s)
    {
        if ((cur % 2 == 0) == (c == '1')){
            cur = cur + 1;
        }
        else{
            cur = cur - 1;
        }

        mn = min(mn, cur);
        mx = max(mx, cur);
    }

    cout << mx - mn << endl;
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    //Codeforces Round 941 (Div. 2)_E	Folding Strip
    return 0;
}