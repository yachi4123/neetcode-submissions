class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,1e9));
        dp[n][m] = grid[n-1][m-1];
        for(int i=n-1;i>=1;i--){
            dp[i][m] = grid[i-1][m-1]+dp[i+1][m];
        }
        for(int i=m-1;i>=1;i--){
            dp[n][i] = grid[n-1][i-1]+dp[n][i+1];
        }
        for(int i=n-1;i>=1;i--){
            for(int j=m-1;j>=1;j--){
                dp[i][j] = grid[i-1][j-1]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[1][1];
    }
};