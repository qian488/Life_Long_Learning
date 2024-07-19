//状压DP
class Solution {
public:
    vector<int> findPermutation(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> f(1 << n, vector<int>(n, INT_MAX));
        vector<vector<int>> g(1 << n, vector<int>(n, -1));
        for (int j = 0; j < n; j++) {
            f[(1 << n) - 1][j] = abs(j - a[0]);
        }
        for (int s = (1 << n) - 3; s > 0; s -= 2) { // 注意偶数不含 0，是无效状态
            for (int j = 0; j < n; j++) {
                if ((s >> j & 1) == 0) { // 无效状态，因为 j 一定在 s 中
                    continue;
                }
                for (int k = 1; k < n; k++) {
                    if (s >> k & 1) { // k 之前填过
                        continue;
                    }
                    int v = f[s | 1 << k][k] + abs(j - a[k]);
                    if (v < f[s][j]) {
                        f[s][j] = v;
                        g[s][j] = k; // 记录该状态下填了哪个数
                    }
                }
            }
        }

        vector<int> ans;
        int s = 0, j = 0;
        while (j >= 0) {
            ans.push_back(j);
            s |= 1 << j;
            j = g[s][j];
        }
        return ans;
    }
};
