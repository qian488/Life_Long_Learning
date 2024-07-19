class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnt(n * n + 1);
        for (auto e : grid) {
            for (int x : e) {
                cnt[x]++;
            }
        }

        vector<int> ans(2);
        for (int i = 1; i <= n * n; i++) {
            if (cnt[i] == 2) {
                ans[0] = i; 
            } else if (cnt[i] == 0) {
                ans[1] = i;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int xor_all = 0;
        for (auto& row : grid) {
            for (int x : row) {
                xor_all ^= x;
            }
        }
        xor_all ^= n % 2 ? 1 : n * n;
        int shift = __builtin_ctz(xor_all);

        vector<int> ans(2);
        for (int x = 1; x <= n * n; x++) {
            ans[x >> shift & 1] ^= x;
        }
        for (auto& row : grid) {
            for (int x : row) {
                ans[x >> shift & 1] ^= x;
            }
        }

        for (auto& row : grid) {
            if (ranges::find(row, ans[0]) != row.end()) {
                return ans;
            }
        }
        return {ans[1], ans[0]};
    }
};

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n * n;
        int d1 = -m * (m + 1) / 2;
        long long d2 = (long long) -m * (m + 1) * (m * 2 + 1) / 6;
        for (auto& row : grid) {
            for (int x : row) {
                d1 += x;
                d2 += x * x;
            }
        }
        int d = d2 / d1;
        return {(d + d1) / 2, (d - d1) / 2};
    }
};
