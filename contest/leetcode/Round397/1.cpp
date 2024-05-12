class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n=s.size();
        int ans=0;
        unordered_map<char,int> smp;
        unordered_map<char,int> tmp;
        for(int i=0;i<n;i++){
            smp[s[i]]=i;
            tmp[t[i]]=i;
        }
        for(int i=0;i<n;i++){
            ans+=abs(smp[s[i]]-tmp[s[i]]);
        }
        return ans;
    }
};