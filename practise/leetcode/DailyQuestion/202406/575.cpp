class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int,int> ctmp;
        for(auto e:candyType) ctmp[e]++;
        int ans=candyType.size()/2;
        ans=min(ans,(int)ctmp.size());
        return ans;
    }
};

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(candyType.begin(), candyType.end());
        return min(s.size(), candyType.size() / 2);
    }
};
