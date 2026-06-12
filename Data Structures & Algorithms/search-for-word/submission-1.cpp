class Solution {
public:

    int dr[4] = {0,0,1,-1};
    int dc[4] = {-1,1,0,0};

    bool solve(int ind, vector<vector<char>>& board, string& word, vector<vector<int>>& vis, int r, int c){
        int n = board.size();
        int m = board[0].size();
        
        if(ind>=word.length())return true;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<n && nr>=0 && nc<m && nc>=0 && board[nr][nc]==word[ind] && vis[nr][nc]==0){
                vis[nr][nc]=1;
                bool ans = solve(ind+1,board,word,vis,nr,nc);
                vis[nr][nc]=0;
                if(ans)return true;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    bool ans = solve(1,board,word,vis,i,j);
                    if(ans==true)return true;
                    vis[i][j]=0;
                }
            }
        }
        return false;
    }
};
