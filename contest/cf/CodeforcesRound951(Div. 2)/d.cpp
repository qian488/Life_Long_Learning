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
#include<bitset>
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (k == 1) {
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                cout << i + 1 << endl;
                break;
            }
        }
    } else if (k == n) {
        cout << -1 << endl;
    } else {
        int p = 0;
        while (s[p] == s[0]) {
            p++;
        }
        cout << p + 1 << endl;
    }
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
