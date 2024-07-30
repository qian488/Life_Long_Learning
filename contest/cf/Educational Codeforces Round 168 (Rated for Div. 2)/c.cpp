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
#include<stack>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF (ll)2e18
#define MOD 100000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ok = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '_'){
            if(ok) s[i] = ')';
            else s[i] = '(';
        }
        ok += (s[i] == '(') ? 1 : -1;
    }

    // cout << s << endl;

    vector<int> stk;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk.push_back(i);
        } else if (s[i] == ')') {
            ans += i - stk.back();
            stk.pop_back();
        }
    }

    cout << ans << endl;
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
