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

// MLE 不管力

void Solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (char ch : s) {
        cnt += (ch != 'a');
    }
    if (cnt == 0) {
        cout << n - 1 << endl;
        return;
    }

    unordered_set<string> st;

    for (int i = 0; i < n; ++i) {
        string tt;
        for (int j = i; j < n; ++j) {
            tt += s[j];
            if (tt != "a") {
                st.insert(tt);
            }
        }
    }

    int ans = 1;

    unordered_map<string, int> kk;
    for (auto tt : st) {
        int pos = 0;
        while ((pos = s.find(tt, pos)) != string::npos) {
            kk[tt]++;
            pos += tt.size();
        }
    }

    for (auto e : kk) {
        string t = e.first;
        if (t.size() == s.size()) continue; 
        bool ok = true;
        for (int i = 0; i < n;) {
            if (s.substr(i, t.size()) == t) {
                i += t.size();
            } else if (s.substr(i, 1) == "a") {
                i++;
            } else {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
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
