class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int l = (2*sum)+1;
        vector<vector<int>>dp(n+1,vector<int>(l,0));
        dp[0][sum]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<l;j++){
                int val = j - sum;
                // minus the current
                if(val+nums[i-1]+sum<l&&val+nums[i-1]+sum>=0){
                    dp[i][j] += dp[i-1][val+nums[i-1]+sum];
                }
                // add the current
                if(val-nums[i-1]+sum<l&&val-nums[i-1]+sum>=0){
                    dp[i][j] += dp[i-1][val-nums[i-1]+sum];
                }
            }
        }
        return dp[n][sum+target];
    }
};
