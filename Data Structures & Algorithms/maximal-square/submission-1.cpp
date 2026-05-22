#include <cstring>
class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int k = min(n,m);
        bool dp[n][m][k];
        memset(dp,false,sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1'){
                    dp[i][j][1] = true;
                    ans = 1;
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(mat[i][j]=='1'){
                    for(int l=2;l<=k;l++){
                        if(dp[i+1][j][l-1]==true&&dp[i][j+1][l-1]==true&&dp[i+1][j+1][l-1]==true){
                            dp[i][j][l]=true;
                            ans=max(ans,l);
                        }
                        else break;
                    }
                }
            }
        }
        return ans*ans;
    }
};