#include<bits/stdc++.h>
using namespace std;

#define int long long

struct segmenttree
{
    int n;
    vector<int> st, lazy;

    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, LLONG_MAX);
        lazy.resize(4 * n, LLONG_MAX);
    }

    void push(int start, int ending, int node)
    {
        if (lazy[node] != LLONG_MAX)
        {
            st[node] = min(lazy[node], st[node]);

            if (start != ending)
            {
                lazy[2 * node + 1] = min(lazy[2 * node + 1],lazy[node]);
                lazy[2 * node + 2] = min(lazy[node], lazy[2 * node + 1]);
            }

            lazy[node] = LLONG_MAX;
        }
    }

    int query(int start, int ending, int l, int r, int node)
    {
        push(start, ending, node);

        if (start > r || ending < l)
        {
            return LLONG_MAX;
        }

        if (start >= l && ending <= r)
        {
            return st[node];
        }

        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return min(q1, q2);
    }

    void update(int start, int ending, int node, int l, int r, int value)
    {
        push(start, ending, node);

        if (start > r || ending < l)
        {
            return;
        }

        if (start >= l && ending <= r)
        {
            lazy[node] = min(lazy[node], value);
            push(start, ending, node);            
            return;
        }

        int mid = (start + ending) / 2;

        update(start, mid, 2 * node + 1, l, r, value);

        update(mid + 1, ending, 2 * node + 2, l, r, value);

        st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);

        return;
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int l, int r, int x)
    {
        update(0, n - 1, 0, l, r, x);
    }
};

// 线段树解法

signed main()
{
    int tt; cin >> tt;

    while(tt--) {
        int n; cin >> n;
        vector<int>a(n), b(n);

        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;

        segmenttree tree; tree.init(n); tree.update(0, 0, 0);

        int sum = 0, answer = 0;

        for(int i = 0; i < n; i++) {
            sum += a[i];
            int query = tree.query(i, i);
            if(query == LLONG_MAX) break;
            else {
                answer = max(answer, sum - query);
                tree.update(0, b[i] - 1, query + a[i]);
            }
        }

        cout << answer << "\n";
    }
}