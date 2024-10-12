class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> cnt(51,0);
        int ans = 0;
        for (int x : nums) {
            cnt[x]++;
            if (cnt[x] == 2) {
                ans ^= x;
            }
        }
        return ans;
    }
};