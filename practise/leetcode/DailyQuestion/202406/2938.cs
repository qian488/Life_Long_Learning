public class Solution {
    public long MinimumSteps(string s) {
        long ans=0;
        int cnt=0;
        foreach(char c in s){
            if(c=='1'){
                cnt++;
            }else{
                ans+=cnt;
            }
        }
        return ans;
    }
}