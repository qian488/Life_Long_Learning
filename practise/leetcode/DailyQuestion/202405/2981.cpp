class Solution {
public:
    int maximumLength(string s) {
        int ans=0;
        vector<int> groups[26];
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt++;
            if(i+1==n||s[i]!=s[i+1]){
                groups[s[i]-'a'].push_back(cnt);
                cnt=0;
            }
        }
        for(auto e:groups){
            if(e.empty()) continue;
            ranges::sort(e,greater());
            e.push_back(0);
            e.push_back(0);
            ans=max({ans,e[0]-2,min(e[0]-1,e[1]),e[2]});
        }
        return ans?ans:-1;
    }
};