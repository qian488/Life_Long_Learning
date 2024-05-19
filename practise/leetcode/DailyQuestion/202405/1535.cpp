class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int ans=arr[0],cnt=0,n=arr.size();
        for(int i=1;i<n&&cnt<k;i++,cnt++){
            if(arr[i]>ans){
                ans=arr[i];
                cnt=0;
            }
        }
        return ans;
    }
};