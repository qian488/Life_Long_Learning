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

struct Node {
    ll t;
    int id;
    bool operator<(const Node &tt) const {
        return t > tt.t;
    }
};

void Solve()
{
    int h, n;
    cin >> h >> n;
    vector<int> a(n + 1), c(n + 1);
    priority_queue<Node> q;
    for (int i = 1; i <= n;i++){ 
        cin >> a[i];
        q.push({1, i});
    }
    for (int i = 1; i <= n;i++) cin >> c[i];
    while (1){
        auto [x, y] = q.top();
        q.pop();
        h -= a[y];
        if(h <= 0) {
            cout << x << endl;
            break;
        }
        q.push({x + c[y], y});

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
