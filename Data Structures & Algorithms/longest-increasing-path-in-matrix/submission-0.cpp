class Solution {
public:

    int dr[4] = {0,0,-1,1};
    int dc[4] = {1,-1,0,0};

    int dfs(int r, int c, vector<vector<int>>&dp, vector<vector<int>>& arr, int prev){
        int rows = arr.size();
        int cols = arr[0].size();
        if(r<0||r>=rows||c<0||c>=cols||arr[r][c]<=prev){
            return 0;
        }
        if(dp[r][c]!=-1)return dp[r][c];
        int res = 1;
        for(int i = 0;i<4;i++){
            res = max(res,1+dfs(r+dr[i],c+dc[i],dp,arr,arr[r][c]));
        }
        dp[r][c]=res;
        return dp[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int lip = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                lip = max(lip,dfs(i,j,dp,arr,INT_MIN));
            }
        }
        return lip; 
    }
};
