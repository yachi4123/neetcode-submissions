class Solution {
public:

    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>&q, vector<vector<int>>&vis, int &blocks, int &cnt){
        int n = vis.size();
        int m = vis[0].size();
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dy[i];
                int nc = c+dx[i];
                if(nr<n&&nr>=0&&nc<m&&nc>=0&&vis[nr][nc]==0&&grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                    cnt++;
                    blocks++;
                }
                else if(nr<n&&nr>=0&&nc<m&&nc>=0&&grid[nr][nc]==1){
                    cnt++;
                }
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int blocks = 0;
        int cnt = 0;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0&&grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({i,j});
                    blocks++;
                    bfs(grid,q,vis,blocks,cnt);
                }
            }
        }
        cout<<blocks<<endl;
        cout<<cnt<<endl;
        return (4*blocks)-cnt;
    }
};