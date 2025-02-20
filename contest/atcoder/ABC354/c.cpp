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
#define MOD 100000000
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

struct Card {
    int a;
    int c;
    int index;
};

void Solve()
{
    int n;
    cin >> n;
    vector<Card> cards(n);
    for (int i = 0; i < n; ++i) {
        int a, c;
        cin >> a >> c;
        cards[i] = {a, c, i};
    }
    
    sort(cards.begin(), cards.end(), [&](const auto &l, const auto &r) {
        return l.c < r.c;
    });
    
    vector<int> ans;
    int v = 0;
    for (int i = 0; i < n; ++i) {
        if (cards[i].a > v) {
            v = cards[i].a;
            ans.push_back(cards[i].index);
        }
    }
    sort(ans.begin(), ans.end());
    
    const int m = (int)ans.size();
    cout << m << endl;
    for (int i = 0; i < m; ++i) {
        cout << ans[i] + 1;
        if (i == m - 1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }
}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
