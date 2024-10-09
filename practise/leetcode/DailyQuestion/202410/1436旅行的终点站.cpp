class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> sa, sb;
        for(auto& p : paths){
            auto& a = p[0];
            auto& b = p[1];
            sb.erase(a);
            if(!sa.contains(b)){
                sb.insert(b);
            }
            sa.insert(a);
        }

    return *sb.begin();
    }
};