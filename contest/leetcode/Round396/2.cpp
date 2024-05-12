class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int ans=0,maxn=0,n=word.size();
        unordered_map<string,int> cnt;
        for(int i=0;i<n;i+=k){
            cnt[word.substr(i,k)]++;
        }
        for(auto e:cnt){
            maxn=max(maxn,e.second);
        }
        ans=n/k-maxn;
        return ans;
    }
};