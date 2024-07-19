/*
TLE
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int ans=-1e9;
        for(int i=0;i<n;i++){
            int sum=energy[i];
            for(int j=i+k;j<n;j+=k){
                sum+=energy[j];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};
*/
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans=-1e9;
        int n=energy.size();
        reverse(energy.begin(),energy.end());
        for(int i=0;i<k;i++){
            int sum=0;
            for(int j=i;j<n;j+=k){
                sum+=energy[j];
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};