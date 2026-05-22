class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0){
            return -1;
        }
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        dis[0][0]=1;
        int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int val = q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int newr = r+dx[i];
                int newc = c+dy[i];
                if(newr<n&&newr>=0&&newc<n&&newc>=0){
                    if(grid[newr][newc]==0){
                        int dist = 1+val;
                        // if(dx[i]!=0&&dy[i]!=0)dist = 2+val;
                        // else dist = 1+val;
                        if(dist<dis[newr][newc]){
                            dis[newr][newc]=dist;
                            q.push({{newr,newc},dist});
                        }
                    }
                }
            }
        }
        if(dis[n-1][n-1]==1e9)return -1;
        return dis[n-1][n-1]; 
    }
};