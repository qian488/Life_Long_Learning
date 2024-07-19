class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        auto solve = [&](int i,int j,int target) -> int{
            for(auto & row : dp){
                ranges::fill(row, -1);
            }
            function<int(int,int)> dfs = [&](int i,int j) -> int{
                if(i >= j) return 0;
                int &res=dp[i][j];
                if (res != -1) return res;
                res = 0;
                if(nums[i]+nums[i+1]==target) res = max(res, dfs(i + 2, j) + 1);
                if(nums[j-1]+nums[j]==target) res = max(res, dfs(i, j - 2) + 1);
                if(nums[i]+nums[j]==target) res = max(res, dfs(i + 1, j - 1) + 1);
                return res;
            }; 
            return dfs(i, j);
        };
        int res1 = solve(2, n - 1, nums[0] + nums[1]);
        int res2 = solve(0, n - 3, nums[n - 2] + nums[n - 1]);
        int res3 = solve(1, n - 2, nums[0] + nums[n - 1]);
        return max({res1,res2,res3}) + 1;
    }
};