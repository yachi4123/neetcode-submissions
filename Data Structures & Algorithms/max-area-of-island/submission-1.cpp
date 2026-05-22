class Solution {
public:

    int dfs(int r, int c, vector<vector<int>>& grid, int area){
        int n = grid.size();
        int m = grid[0].size();
        if(r>=n||c>=m||r<0||c<0||grid[r][c]==0||grid[r][c]==-1)return 0;
        grid[r][c]=-1;
        int val = area;
        area+= dfs(r-1,c,grid,val);
        area+= dfs(r+1,c,grid,val);
        area+= dfs(r,c-1,grid,val);
        area+= dfs(r,c+1,grid,val);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area = 1;
                    ans = max(ans,dfs(i,j,grid,area));
                }
            }
        }
        return ans;
    }
};
