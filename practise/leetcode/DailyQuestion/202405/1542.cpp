class Solution {
    const int D=10;
public:
// 异或前缀和
    int longestAwesome(string s) {
        int n = s.size();
        vector<int> pos(1 << D, n); // n 表示没有找到异或前缀和
        pos[0] = -1; // pre[-1] = 0
        int ans = 0, pre = 0;
        for (int i = 0; i < n; i++) {
            pre ^= 1 << (s[i] - '0');
            for (int d = 0; d < D; d++) {
                ans = max(ans, i - pos[pre ^ (1 << d)]); // 奇数
            }
            ans = max(ans, i - pos[pre]); // 偶数
            if (pos[pre] == n) { // 首次遇到值为 pre 的前缀异或和，记录其下标 i
                pos[pre] = i;
            }
        }
        return ans;
    }
};