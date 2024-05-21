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

struct Node {
    int x1, x2, y1, y2;
} d[N];

// 计算切割的积分
void Solve()
{
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    vector<int> tt(n), kk(n);
    for (int i = 0; i < n; i++){
        cin >> tt[i] >> kk[i];
    }
    int x1 = 1, x2 = a, y1 = 1, y2 = b;
    for (int i = 0; i < m; i++){
        char op;
        int k;
        cin >> op >> k;
        if (op == 'U'){
            x1 += k;
        }else if (op == 'D'){
            x2 -= k;
        }else if (op == 'L'){
            y1 += k;
        }else if (op == 'R'){
            y2 -= k;
        }
        d[i] = {x1, x2, y1, y2};
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {

        int l = 0, r = m;
        while (l < r) {
            int mid = l + r >> 1;
            int u1 = d[mid].x1, u2 = d[mid].x2, v1 = d[mid].y1, v2 = d[mid].y2;
            if (!(tt[i] >= u1 && tt[i] <= u2 && kk[i] >= v1 && kk[i] <= v2)){ 
                r = mid;
            }else{ 
                l = mid + 1;
            }
        }

        if (l != m ) {
            if (l % 2 == 0){ 
                ans1++;
            }else{
                ans2++;
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
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
