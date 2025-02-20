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
    FenwickTree ft(n);

    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        ft.update(i, val);
    }

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            ft.update(b + 1, c);
        } else {
            cout << ft.query(b + 1, c) << endl;
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