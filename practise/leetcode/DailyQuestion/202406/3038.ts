function maxOperations(nums: number[]): number {
    let s=nums[0]+nums[1];
    let ans=1;
    for(let i=3;i<nums.length&&nums[i-1]+nums[i]==s;i+=2){
        ans++;
    }
    return ans;
};