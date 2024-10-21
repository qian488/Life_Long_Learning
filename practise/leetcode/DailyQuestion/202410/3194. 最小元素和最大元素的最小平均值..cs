public class Solution {
    public double MinimumAverage(int[] nums) {
        int n = nums.Length;
        Array.Sort(nums);
        double ans = (nums[n/2]+nums[n/2 - 1])/2.0;
        for (int i=0;i<n/2;i++){
            ans = Math.Min(ans,(nums[i]+nums[n-i-1])/2.0);
        }
        return ans;
    }
}