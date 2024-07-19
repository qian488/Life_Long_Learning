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
    int cnt = 0, minn = n, maxn = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt++;
            minn = min(minn, i);
            maxn = max(maxn, i);
        }
    }
    cout << (cnt % 2 == 1 || (cnt == 2 && maxn - minn == 1) ? "NO" : "YES") << endl;
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