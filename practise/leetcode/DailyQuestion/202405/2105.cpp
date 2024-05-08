class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int ans=0,a=capacityA,b=capacityB;
        int n=plants.size();
        for(int i=0,j=n-1;i<=j;i++,j--){
            if(i==j){
                if(max(a,b)<plants[i]) ans++;
                break;
            }
            if(a<plants[i]){ 
                ans++;
                a=capacityA;
            }
            if(b<plants[j]){
                ans++;
                b=capacityB;
            }
            a-=plants[i];
            b-=plants[j];
        }
        
        return ans;
    }
};