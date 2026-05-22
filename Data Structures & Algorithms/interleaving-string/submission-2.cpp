class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if(n3!=n1+n2)return false;
        vector<vector<bool>>dp(n1+1,vector<bool>(n2+1,false));
        dp[0][0]=true;
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                bool first = false;
                bool second = false;
                if(i==0&&j==0)continue;
                if(i-1>=0){
                    first = dp[i-1][j] && (s1[i-1]==s3[i+j-1]);
                }
                if(j-1>=0){
                    second = dp[i][j-1] && (s2[j-1]==s3[i+j-1]);
                }
                dp[i][j] = (first||second);   
            }
        }
        return dp[n1][n2];
    }
};
