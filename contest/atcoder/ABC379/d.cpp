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
    int q;
    cin>>q;
    multiset<ll> plants;
    ll offset = 0;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            plants.insert(0-offset);
        }else if(op==2){
            ll t;cin>>t;
            offset += t;
        }else if(op==3){
            ll h;cin>>h;
            auto it = plants.lower_bound(h-offset);
            int ans = distance(it, plants.end());
            plants.erase(it, plants.end());
            cout << ans << endl;
        }
    }

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
