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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int ans = 1;
    for (int i = 0; i < 20;i++){
        vector<int> tt;
        for (int j = 0; j < n;j++){
            if (a[j]&(1<<i)){
                tt.push_back(j);
            }
        }

        if (!tt.empty()){
            tt.insert(tt.begin(), -1);
            tt.push_back(n);

            cout << "=============================" << endl;
            for(auto e:tt) cout << e << " ";
            cout << endl;

            for (int j = 1; j < tt.size(); j++){
                ans = max(ans, tt[j] - tt[j - 1]);
            }
            cout << ans << endl;
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
