class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        // base cases
        // dp[i][0] --> profit while purchasing on day i 
        // dp[i][1] --> - - - - - - selling on day i
        // dp[i][2] --> - - - - - - doing nothing on day i
        dp[1][0] = -1*prices[0];
        dp[1][1] = 0;
        for(int i=2;i<=n;i++){
            // buying
            dp[i][0] = max(dp[i-2][1]-prices[i-1],dp[i-1][0]);
            // selling
            dp[i][1] = max(prices[i-1]+dp[i-1][0],dp[i-1][1]);
        }
        return dp[n][1];
    }
};
