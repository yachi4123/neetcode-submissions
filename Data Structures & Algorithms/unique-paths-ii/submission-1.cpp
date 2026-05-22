class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[n-1][m-1]==1)return 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[n][m]=1;
        for(int i=n-1;i>=1;i--){
            if(grid[i-1][m-1]==1)break;
            dp[i][m]=1;
        }
        for(int i=m-1;i>=1;i--){
            if(grid[n-1][i-1]==1)break;
            dp[n][i]=1;
        }
        for(int i=n-1;i>=1;i--){
            for(int j=m-1;j>=1;j--){
                if(grid[i-1][j-1]==1)continue;
                dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[1][1];
    }
};