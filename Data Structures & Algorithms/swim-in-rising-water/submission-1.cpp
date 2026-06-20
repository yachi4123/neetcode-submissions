class Solution {
public:
    int dr[4] = {0,0,1,-1};
    int dc[4] = {-1,1,0,0};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>time(n,vector<int>(n,1e9));
        time[0][0] = grid[0][0];
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            int t = time[r][c];
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr<n && nc<n && nr>=0 && nc>=0){
                    int nt = 1e9;
                    (grid[nr][nc]<grid[r][c]?nt = t:nt = max(grid[nr][nc],t));
                    if(nt<time[nr][nc]){
                        time[nr][nc] = nt;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return time[n-1][n-1];
    }
};
