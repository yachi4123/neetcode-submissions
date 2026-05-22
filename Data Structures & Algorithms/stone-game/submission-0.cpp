#include <cstring>
class Solution {
public:
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int dp[n+1][n+1][2];
        memset(dp,0,sizeof(dp));
        for(int i = 1;i<=n;i++){ 
            dp[i][i][1] = piles[i-1]; // bob
            dp[i][i][0] = 0;  // alice
        }
        for(int diff=1;diff<n;diff++){
            for(int l = 1;l+diff<=n;l++){
                int r = l+diff;
                if((r-l+1)%2==0){ // alice's move
                    if(piles[r-1]+dp[l][r-1][0]>piles[l-1]+dp[l+1][r][0]){
                        dp[l][r][0] = piles[r-1]+dp[l][r-1][0];
                        dp[l][r][1] = dp[l][r-1][1];
                    }
                    else{
                        dp[l][r][0] = piles[l-1]+dp[l+1][r][0];
                        dp[l][r][1] = dp[l+1][r][1];
                    }
                }
                else{ // bob's moves
                    if(piles[r-1]+dp[l][r-1][1]>piles[l-1]+dp[l+1][r][1]){
                        dp[l][r][1] = piles[r-1]+dp[l][r-1][1];
                        dp[l][r][0] = dp[l][r-1][0];
                    }
                    else{
                        dp[l][r][1] = piles[l-1]+dp[l+1][r][1];
                        dp[l][r][0] = dp[l+1][r][0];
                    }
                } 
            }
        }
        if(dp[1][n][0]>dp[1][n][1])return true;
        return false;
    }
};