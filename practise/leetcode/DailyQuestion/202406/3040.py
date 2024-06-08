class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        @cache
        def dfs(i: int, j: int, target: int) -> int:
            if i >= j:
                return 0;
            res = 0
            if nums[i] + nums[i +1 ] == target:
                res = max(res, dfs(i + 2, j, target) + 1)
            if nums[j - 1] + nums[j] == target:
                res = max(res, dfs(i, j - 2,target) + 1)
            if nums[i] + nums[j] == target:
                res = max(res, dfs(i + 1, j - 1, target) + 1)
            return res

        n = len(nums)
        res1 = dfs(2, n - 1, nums[0] + nums[1])
        res2 = dfs(0, n - 3, nums[-2] + nums[-1])
        res3 = dfs(1, n - 2, nums[0] + nums[-1])
        return max(res1, res2, res3) + 1