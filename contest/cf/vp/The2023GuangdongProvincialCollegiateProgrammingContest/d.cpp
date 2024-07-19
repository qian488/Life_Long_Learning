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
    int n, m;
    cin >> n >> m;
    vector<pii> p, q;
    for (int i = 0; i < n;i++){
        int a, b;
        cin >> a >> b;
        if (a<b){
            p.push_back({a, b});
        }else{
            q.push_back({a, b});
        }
    }
    ll ans = 0;

    sort(p.begin(), p.end(), [&](pii i, pii j)
         { return i.second < j.second; }); // 单独的，按b升序
    sort(q.begin(), q.end(), [&](pii i, pii j)
         { return i.first > j.second; }); // 有邻的，按a降序

    int tt = p.size(),kk = q.size();
    if(tt+kk==m){
        for(auto e:p) ans += min(e.first, e.second);
        for(auto e:q) ans += max(e.first, e.second);
        cout << ans << endl;
        return;
    }
    int k = m - tt - kk;
    if(k){
        // 人与人的a和b不一样的，有可能一个人的单独的b比一个人有邻的a小的情况这类的
        while(k--&&!p.empty()){
            ans += p.back().second;
            p.pop_back();
        }
        if(!p.empty()) for(auto e:p) ans += min(e.first, e.second);

        if(kk!=1){
            for(auto e:q) ans += max(e.first, e.second);
        }else{
            for(auto e:q) ans += min(e.first, e.second);
        }

    }
    /*else{
        for(auto e:p) ans += max(e.first, e.second);
        if(kk<=m-tt*2&&kk!=1){
            for(auto e:q) ans += max(e.first, e.second);
        }else{
            for(auto e:q) ans += min(e.first, e.second);
            
        }
    }*/
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
