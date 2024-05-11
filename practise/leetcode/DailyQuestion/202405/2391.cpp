class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=garbage[0].size();
        unordered_set<char> tt;
        for(int i=garbage.size()-1;i>0;i--){
            auto g=garbage[i];
            tt.insert(g.begin(),g.end());
            ans+=g.size()+travel[i-1]*tt.size();
        }
        return ans;
    }
};