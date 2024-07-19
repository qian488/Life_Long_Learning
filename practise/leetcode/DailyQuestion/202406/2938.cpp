class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int cnt=0;
        for(char c:s){
            if(c=='1'){
                cnt++;
            }else{
                ans+=cnt;
            }
        }
        return ans;
    }
};