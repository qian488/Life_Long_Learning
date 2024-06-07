class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int s=nums[0]+nums[1];
        int ans=1;
        for(int i=3;i<nums.size()&&nums[i-1]+nums[i]==s;i+=2){
            ans++;
        }
        return ans;
    }
};