public class Solution {
    int[] nums;
    int[][] dp;
    public int MaxOperations(int[] nums) {
        int n = nums.Length;
        this.nums = nums;
        this.dp = new int[n][];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[n];
        }
        int res = 0;
        res = Math.Max(res, Solve(0, n - 1, nums[0] + nums[n - 1]));
        res = Math.Max(res, Solve(0, n - 1, nums[0] + nums[1]));
        res = Math.Max(res, Solve(0, n - 1, nums[n - 2] + nums[n - 1]));
        return res;
    }

    public int Solve(int i, int j, int target) {
        for (int k = 0; k < nums.Length; k++) {
            Array.Fill(dp[k], -1);
        }
        return Dfs(i, j, target);
    }

    public int Dfs(int i, int j, int target) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (nums[i] + nums[i + 1] == target) {
            ans = Math.Max(ans, Dfs(i + 2, j, target) + 1);
        }
        if (nums[j - 1] + nums[j] == target) {
            ans = Math.Max(ans, Dfs(i, j - 2, target) + 1);
        }
        if (nums[i] + nums[j] == target) {
            ans = Math.Max(ans, Dfs(i + 1, j - 1, target) + 1);
        }
        dp[i][j] = ans;
        return ans;
    }
}