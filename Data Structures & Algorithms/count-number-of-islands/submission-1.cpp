class Solution {
public:

    void dfs(int r, int c, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(r>=n||r<0||c>=m||c<0||grid[r][c]=='a'||grid[r][c]=='0')return;
        grid[r][c]='a';
        dfs(r-1,c,grid);
        dfs(r+1,c,grid);
        dfs(r,c-1,grid);
        dfs(r,c+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};
