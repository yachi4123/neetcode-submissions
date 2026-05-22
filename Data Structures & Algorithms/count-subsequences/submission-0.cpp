class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=n1;i>=0;i--){
            dp[i][n2]=1;
        }
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                }
                else dp[i][j] = dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};
