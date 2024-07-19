public class Solution {
    public int MaxOperations(int[] nums) {
        int s=nums[0]+nums[1];
        int ans=1;
        for(int i=3;i<nums.Length&&nums[i-1]+nums[i]==s;i+=2){
            ans++;
        }
        return ans;
    }
}

public class Solution {
    public int MaxOperations(int[] nums) {
        int s=nums[0]+nums[1];
        for(int i=3;i<nums.Length;i+=2){
            if(nums[i-1]+nums[i]!=s){
                return i/2;
            }
        }
        return nums.Length/2;
    }
}