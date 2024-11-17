#include <bits/stdc++.h>
#include <random>
using namespace std;
#define int long long
typedef long double ld;
typedef int ll;
typedef unsigned long long ull;
#define lowbit(x) ((x)&(-x))
#define endl '\n';

// ST表

template<typename T> vector<vector<T>> get_st(vector<T> &v, T (*sel)(T a, T b)) {
    int n = v.size(), m = log2(n)+1;
    vector<vector<T>> ret(m);
    ret[0] = v;
    for(int i=1;i<m;i++) for(int j=0;j<=n-(1<<i);j++) ret[i].push_back(sel(ret[i-1][j],ret[i-1][j+(1<<(i-1))]));
    return ret;
}

template<typename T> T st_queue(vector<vector<T>> &st, int l, int r, T (*sel)(T a, T b)) {
    int lay = log2(r-l+1), wid=1<<lay;
    return sel(st[lay][l],st[lay][r-wid+1]);
}

int get_max(int a, int b) {
    return max(a,b);
}

void solve() {
    
    int n,q;cin>>n>>q;

    vector<int> v(n);

    for(auto &e:v) cin>>e;

    vector<pair<int,int>> query(q);
    vector<vector<int>> QUERY(n);

    map<pair<int,int>,int> ans;

    for(int i=0;i<q;i++) {
        int l,r;cin>>l>>r;
        l--,r--;
        query[i]={l,r};
        QUERY[r].push_back(l);
    }

    auto st=get_st(v,get_max);

    vector<int> w;

    for(int i=n-1;i>=0;i--) {
        for(auto l:QUERY[i]) {
            int lb=st_queue(st,l+1,i,get_max);
            ans[{l,i}]=(int)w.size()-(lower_bound(w.rbegin(),w.rend(),lb)-w.rbegin());
        }
        while(w.size() && w.back()<v[i]) w.pop_back();
        w.push_back(v[i]);
    }

    for(auto e:query) cout<<ans[e]<<endl;
}

main() {
 
	ios::sync_with_stdio(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--) {
        solve();
    }

    return 0;
}