class Solution {
public:

    int dr[4] = {0,0,-1,1};
    int dc[4] = {1,-1,0,0};
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int r = -1;
        int c = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    r = i;
                    c = j;
                }
            }
        }
        vector<vector<int>>dis(n,vector<int>(n,1e7));
        dis[r][c]=0;
        queue<pair<int,int>>q;
        q.push({r,c});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            int dist = dis[row][col];
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row+dr[i];
                int ncol = col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){
                    if(grid[nrow][ncol]==0 && dis[nrow][ncol]>dist+1){
                        q.push({nrow,ncol});
                        dis[nrow][ncol]=dist+1;
                    }
                    else if(grid[nrow][ncol]==1){
                        if(dis[nrow][ncol]>dist){
                            q.push({nrow,ncol});
                            dis[nrow][ncol] = dist;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans=max(ans,dis[i][j]);
                }
            }
        }
        return ans;
    }
};