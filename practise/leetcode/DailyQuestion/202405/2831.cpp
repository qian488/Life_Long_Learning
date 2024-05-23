class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int ans=0,n=nums.size();
        unordered_map<int,vector<int>> nmp;
        for(int i=0;i<n;i++){
            int t=nums[i];
            nmp[t].push_back(i);
        } 
        for(auto [e,p]:nmp){
            for(int i=0,j=0;i<p.size();i++){
                while(p[i]-p[j]-(i-j)>k) j++;
                ans=max(ans,i-j+1);
            }
        }
        return ans;
    }
};