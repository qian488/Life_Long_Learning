#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll qmi(ll m,ll k,ll p)
{
    ll res=1%p,t=m;
    while(k)
    {
        if(k&1) res=res*t%p;
        t=t*t%p;
        k>>=1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    ll k;
    cin >> n >> k;
    
    vector<int> p(n+1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    
    vector<int> ans(n+1);
    vector<bool> vis(n+1, false);
    
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vector<int> cycle;
            int cur = i;
            while(!vis[cur]) {
                cycle.push_back(cur);
                vis[cur] = true;
                cur = p[cur];
            }
            
            int len = cycle.size();
            int kk = qmi(2, k, len);
            
            for(int j = 0; j < len; j++) {
                ans[cycle[j]] = cycle[(j + kk) % len];
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }
    
    return 0;
}

/*
重要的数学性质：对于任何置换，其2^K次幂等价于将其循环K次。
解释：
对于任何置换，其阶（order）是将置换恢复到初始状态所需的最小操作次数。
2^K mod order(P) 等价于 K mod order(P)，但前者可以通过快速幂算法更高效地计算，尤其是对于非常大的K值。
*/
