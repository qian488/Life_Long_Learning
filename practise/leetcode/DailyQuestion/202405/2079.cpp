class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0,t=capacity;
        int n=plants.size();
        for(int i=0;i<n;i++){
            if(t<plants[i]){
                t=capacity;
                ans+=i*2;
            }
            t-=plants[i];
            ans++;
        }
        return ans;
    }
};