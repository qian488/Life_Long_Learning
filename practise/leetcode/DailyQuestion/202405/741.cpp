class Solution {
    //线性DP
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,(int)-1e9));
        dp[1][1]=grid[0][0];
        for(int k=1;k<=n*2;k++){
            for(int i=min(k,n-1);i>=max(k-n+1,0);i--){
                for(int j=min(k,n-1);j>=i;j--){
                    int u=k-i,v=k-j;
                    if(grid[i][u]==-1||grid[j][v]==-1){
                        dp[i+1][j+1]=(int)-1e9; 
                        continue;
                    }
                    dp[i+1][j+1]=max({dp[i+1][j+1],dp[i+1][j],dp[i][j+1],dp[i][j]});
                    dp[i+1][j+1]+=grid[i][u]+((i!=j)?grid[j][v]:0);
                }
            }
        }
        return max(dp[n][n],0);
    }
};