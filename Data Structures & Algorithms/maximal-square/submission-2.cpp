#include <cstring>
class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int k = min(n,m);
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1'){
                    dp[i][j] = 1;
                    ans = 1;
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(mat[i][j]=='1'){
                    dp[i][j] = 1+min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans*ans; 
    }
};