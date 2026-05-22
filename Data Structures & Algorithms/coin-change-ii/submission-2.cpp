class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(amount+1,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=amount;i++){
            for(int j=n-1;j>=0;j--){
                if(coins[j]<=i){
                    if(j+1<n){
                        dp[i][j] = dp[i][j+1]+dp[i-coins[j]][j];
                    }
                    else dp[i][j] = dp[i-coins[j]][j];
                }
            }
        }
        return dp[amount][0];
    }
};
