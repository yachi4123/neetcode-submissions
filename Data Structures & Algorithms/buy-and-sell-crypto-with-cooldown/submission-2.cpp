class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1e9));
        // base cases
        // dp[i][0] --> profit while purchasing on day i 
        // dp[i][1] --> - - - - - - selling on day i
        // dp[i][2] --> - - - - - - doing nothing on day i
        dp[1][0] = -1*prices[0];
        dp[1][2] = 0;
        dp[0][2] = 0;
        for(int i=2;i<=n;i++){
            // purchasing
            for(int j = 0;j<i-1;j++){
                dp[i][0] = max(dp[i][0], -1*prices[i-1] + max({dp[j][1],dp[j][2]}));
            }
            // selling
            for(int j = 0;j<i;j++){
                dp[i][1] = max(dp[i][1], prices[i-1] + dp[j][0]);
            }
            // doing nothing
            dp[i][2] = max({dp[i-1][1],dp[i-1][2],dp[i-1][0]});
        }
        return max({dp[n][0],dp[n][1],dp[n][2]});
    }
};
