class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans=-1e9;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> f(n+1,vector<int> (m+1,1e9));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int minn=min(f[i+1][j],f[i][j+1]);
                ans=max(ans,grid[i][j]-minn);
                f[i+1][j+1]=min(minn,grid[i][j]);
            }
        }
        return ans;
    }
};