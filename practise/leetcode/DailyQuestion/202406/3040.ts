function maxOperations(nums: number[]): number {
    const n = nums.length;  
    const solve = (i: number, j: number, target: number): number => {
        const dp: number[][] = Array.from({length: n}, () => Array(n).fill(-1));
        const dfs = (i: number, j: number): number => {
            if (i >= j) return 0;
            if (dp[i][j] !== -1) return dp[i][j];
            let res = 0;
            if (nums[i] + nums[i + 1] === target) res = Math.max(res, dfs(i + 2, j) + 1);
            if (nums[j - 1] + nums[j] === target) res = Math.max(res, dfs(i, j - 2) + 1);
            if (nums[i] + nums[j] === target) res = Math.max(res, dfs(i + 1, j - 1) + 1);
            dp[i][j] = res;
            return res;
        };
        return dfs(i,j);
    };
    let res = 0; 
    res = Math.max(res,solve(0, n - 1, nums[0] + nums[1]));
    res = Math.max(res,solve(0, n - 1, nums[n - 2] + nums[n - 1]));
    res = Math.max(res,solve(0, n - 1, nums[0] + nums[n - 1]));
    return res;
};