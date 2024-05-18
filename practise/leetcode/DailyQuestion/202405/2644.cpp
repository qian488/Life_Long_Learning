class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans=0,maxn=-1;
        for(int d:divisors){
            int cnt=ranges::count_if(nums,[&](int x){return x%d==0;});
            if(cnt>maxn||cnt==maxn&&d<ans){
                ans=d;
                maxn=cnt;
            }
        }

        return ans;
    }
};