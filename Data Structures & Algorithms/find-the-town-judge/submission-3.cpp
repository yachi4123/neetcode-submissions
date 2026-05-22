class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>in(n+1,0);
        vector<int>ou(n+1,0);
        int sz = trust.size();
        for(int i=0;i<sz;i++){
            int u = trust[i][0];
            int v = trust[i][1];
            in[v]++;
            ou[u]++;
        }
        int ans = -1;
        for(int i=0;i<=n;i++){
            if(in[i]==n-1&&ou[i]==0&&ans==-1){
                ans = i;
            }
        }
        return ans;
    }
};