/// <summary>
/// 暴力解法，直接枚举
/// </summary>
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int n = nums.Length;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j] == target){
                    return new int[] { i, j };
                }
            }
        }
        return new int[0];
    }
}

/// <summary>
/// O(n)
/// 使用字典存储
/// 枚举 target - nums[i]
/// </summary>
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int n = nums.Length;
        Dictionary<int,int> d = new Dictionary<int,int>();

        for (int i = 0; i < n; i++) {
            if (!d.ContainsKey(nums[i])) {
                d.Add(nums[i], i);
            }
        }

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            
            if (d.ContainsKey(complement) && d[complement] != i) {
                return new int[] { i, d[complement] };
            }
        }

        return new int[0]; 
    }
}