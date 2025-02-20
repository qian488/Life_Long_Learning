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
#define MOD 998244353
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

// 二进制枚举

void Solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v[m];
    vector<char> r(m);
    for(int i=0;i<m;i++){
        int c;
        cin >> c;
        for(int j=0;j<c;j++){
            int a;
            cin >> a;
            a--;
            v[i].push_back(a);
        }
        cin >> r[i];
    }

    int ans = 0;
    for(int mask=0;mask<(1<<n);mask++){
        bool ok = true;
        for(int i=0;i<m;i++){
            int cnt = 0;
            for(auto e:v[i]) cnt += (mask>>e)&1;
            ok &= ((cnt >= k) == (r[i] == 'o'));
        }
        ans += ok;
    }
    cout << ans << endl;
}

int main()
{
    ios 
    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
