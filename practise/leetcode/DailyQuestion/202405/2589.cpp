class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        ranges::sort(tasks, [](auto& a, auto& b) { return a[1] < b[1]; });
        int ans = 0;
        vector<int> run(tasks.back()[1] + 1);
        for (auto& t : tasks) {
            int start = t[0], end = t[1], d = t[2];
            d -= reduce(run.begin() + start, run.begin() + end + 1); // 去掉运行中的时间点
            for (int i = end; d > 0; i--) { // 剩余的 d 填充区间后缀
                if (!run[i]) {
                    run[i] = true; // 运行
                    d--;
                    ans++;
                }
            }
        }
        return ans;
    }
};

class Solution {
    vector<int> cnt, todo;

    void do_(int o, int l, int r) {
        cnt[o] = r - l + 1;
        todo[o] = true;
    }

    void spread(int o, int l, int m, int r) {
        if (todo[o]) {
            do_(o * 2, l, m);
            do_(o * 2 + 1, m + 1, r);
            todo[o] = false;
        }
    }

    // 查询区间 [L,R]   o,l,r=1,1,u
    int query(int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) return cnt[o];
        int m = (l + r) / 2;
        spread(o, l, m, r);
        if (m >= R) return query(o * 2, l, m, L, R);
        if (m < L) return query(o * 2 + 1, m + 1, r, L, R);
        return query(o * 2, l, m, L, R) + query(o * 2 + 1, m + 1, r, L, R);
    }

    // 新增区间 [L,R] 后缀的 suffix 个时间点    o,l,r=1,1,u
    // 相当于把线段树二分和线段树更新合并成了一个函数，时间复杂度为 O(log MX)
    void update(int o, int l, int r, int L, int R, int& suffix) {
        int size = r - l + 1;
        if (cnt[o] == size) return; // 全部为运行中
        if (L <= l && r <= R && size - cnt[o] <= suffix) { // 整个区间全部改为运行中
            suffix -= size - cnt[o];
            do_(o, l, r);
            return;
        }
        int m = (l + r) / 2;
        spread(o, l, m, r);
        if (m < R) update(o * 2 + 1, m + 1, r, L, R, suffix); // 先更新右子树
        if (suffix) update(o * 2, l, m, L, R, suffix); // 再更新左子树（如果还有需要新增的时间点）
        cnt[o] = cnt[o * 2] + cnt[o * 2 + 1];
    }

public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        ranges::sort(tasks, [](auto& a, auto& b) { return a[1] < b[1]; });
        int u = tasks.back()[1];
        int m = 2 << (32 - __builtin_clz(u));
        cnt.resize(m);
        todo.resize(m);
        for (auto& t : tasks) {
            int start = t[0], end = t[1], d = t[2];
            d -= query(1, 1, u, start, end);  // 去掉运行中的时间点
            if (d > 0) update(1, 1, u, start, end, d); // 新增时间点
        }
        return cnt[1];
    }
};

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        ranges::sort(tasks, [](auto& a, auto& b) { return a[1] < b[1]; });
        // 栈中保存闭区间左右端点，栈底到栈顶的区间长度的和
        vector<array<int, 3>> st{{-2, -2, 0}}; // 哨兵，保证不和任何区间相交
        for (auto& t : tasks) {
            int start = t[0], end = t[1], d = t[2];
            auto [_, r, s] = *--ranges::lower_bound(st, start, {}, [](auto& x) { return x[0]; });
            d -= st.back()[2] - s; // 去掉运行中的时间点
            if (start <= r) { // start 在区间 st[i] 内
                d -= r - start + 1; // 去掉运行中的时间点
            }
            if (d <= 0) {
                continue;
            }
            while (end - st.back()[1] <= d) { // 剩余的 d 填充区间后缀
                auto [l, r, _] = st.back();
                st.pop_back();
                d += r - l + 1; // 合并区间
            }
            st.push_back({end - d + 1, end, st.back()[2] + d});
        }
        return st.back()[2];
    }
};
