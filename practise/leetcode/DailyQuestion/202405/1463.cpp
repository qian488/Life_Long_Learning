class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+2,vector<int>(n+2)));
        for(int k=m-1;k>=0;k--){
            for(int i=0;i<min(n,k+1);i++){
                for(int j=max(i+1,n-k-1);j<n;j++){
                    dp[k][i+1][j+1]=max({
                        dp[k+1][i][j],dp[k+1][i][j+1],dp[k+1][i][j+2],
                        dp[k+1][i+1][j],dp[k+1][i+1][j+1],dp[k+1][i+1][j+2],
                        dp[k+1][i+2][j],dp[k+1][i+2][j+1],dp[k+1][i+2][j+2]
                    })+grid[k][i]+grid[k][j];
                }
            }
        }
        return dp[0][1][n];
    }
};