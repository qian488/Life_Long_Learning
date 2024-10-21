using System;

public class Solution {
    public int SmallestRangeII(int[] nums, int k) {
        Array.Sort(nums);
        int n = nums.Length;
        int minScore = nums[n - 1] - nums[0];

        for (int i = 0; i < n - 1; i++) {
            int high = Math.Max(nums[i] + k, nums[n - 1] - k);
            int low = Math.Min(nums[0] + k, nums[i + 1] - k);
            minScore = Math.Min(minScore, high - low);
        }
        
        return minScore;
    }
}
