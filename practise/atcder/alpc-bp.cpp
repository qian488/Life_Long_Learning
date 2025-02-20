#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct FenwickTree {
    vector<int> tree;
    int n;

    FenwickTree() {}
    FenwickTree(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        tree.resize(n + 1, 0);
    }

    int lowbit(int x) {
        return x & -x;
    }

    void update(int x, int k) {
        while (x <= n) {
            tree[x] += k;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int res = 0;
        while (x > 0) {
            res += tree[x];
            x -= lowbit(x);
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    FenwickTree ft(n);

    for (int i = 1; i <= n; i++) cin>>a[i];

    while (q--) {
        int op;
        cin >> op;
        if(op==1){
            int l,r,x;
            cin>>l>>r>>x;
            ft.update(l,x);
            ft.update(r+1,-x);
        }else{
            int x;
            cin>>x;
            cout<<a[x]+ft.query(x)<<endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}