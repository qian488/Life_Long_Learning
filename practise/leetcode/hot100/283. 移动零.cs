/// <summary>
/// 双指针？大概
/// 就是先将有多少非零元素统计出来，然后在此索引上继续填0
/// </summary>
public class Solution {
    public void MoveZeroes(int[] nums) {
        int n = nums.Length;
        int index=0;

        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[index++] = nums[i];
            }
        }

        for(int i=index;i<n;i++){
            nums[i]=0;
        }
    }
}