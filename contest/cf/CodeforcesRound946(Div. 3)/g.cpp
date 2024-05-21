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

void Solve()
{
    int m, x;
    cin >> m >> x;
    vector<int> a(m);
    int s = 0;
    priority_queue<int> q;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        if (s >= a[i]) {
            s -= a[i];
            q.push(a[i]);
        } else if (q.size() && a[i] < q.top()) {
            s += q.top() - a[i];
            q.pop();
            q.push(a[i]);
        }
        s += x;
    }
    cout << q.size() << endl;
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
