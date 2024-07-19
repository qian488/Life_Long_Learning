class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0;
        int n=tasks.size();
        unordered_map<int,int> tmp;
        for(int i=0;i<n;i++){
            tmp[tasks[i]]++;
        }
        for(auto e:tmp){
            if(e.second==1){
                return -1;
            }
            ans+=(e.second+2)/3;
        }
        return ans;
    }
};