
class Solution {
public:

    int t = 2147483647;
    int dr[4] = {0,0,-1,1};
    int dc[4] = {1,-1,0,0};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr<n&&nc<m&&nr>=0&&nc>=0&&grid[nr][nc]==t){
                    int ndis = dis+1;
                    q.push({{nr,nc},ndis});
                    grid[nr][nc] = ndis;
                }
            }
        }
    }
};
