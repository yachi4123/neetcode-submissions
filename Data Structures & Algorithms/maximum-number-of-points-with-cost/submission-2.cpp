#define ll long long
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
        vector<ll>preLeft(m+1,0);
        vector<ll>sufRight(m+1,0);
        for(int i=1;i<=m;i++){
            dp[1][i]=points[0][i-1];
            preLeft[i]=max(preLeft[i-1],dp[1][i]+i);
        }
        sufRight[m] = dp[1][m]-m;
        for(int j=m-1;j>=1;j--){
            sufRight[j] = max(sufRight[j+1],dp[1][j]-j);
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = points[i-1][j-1] + max({preLeft[j-1]-j,sufRight[j]+j});
            }
            for(int j=1;j<=m;j++){
                preLeft[j]=0;
                preLeft[j]=max(preLeft[j-1],dp[i][j]+j);
            }
            sufRight[m] = dp[i][m]-m;
            for(int j=m-1;j>=1;j--){
                sufRight[j] = max(sufRight[j+1],dp[i][j]-j);
            }
        }
        ll ans = 0;
        for(int j=1;j<=m;j++){
            ans = max(ans,dp[n][j]);
        }
        return ans;
    }
};