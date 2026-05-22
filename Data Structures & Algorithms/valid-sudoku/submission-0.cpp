class Solution {
public:

    bool checkForSubBox(vector<vector<char>>& board, char ch, int r, int c){
        int row = (r/3)*3;
        int col = (c/3)*3;
        for(int i = row;i<row+3;i++){
            for(int j = col;j<col+3;j++){
                if(i!=r || j!=c){
                    if(board[i][j]==ch){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool checkForRow(int r, int c, char ch, vector<vector<char>>& board){
        for(int j=0;j<9;j++){
            if(j!=c){
                if(board[r][j]==ch){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkForCol(int r, int c, char ch, vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(i!=r){
                if(board[i][c]==ch){
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch = board[i][j];
                if(ch=='.')continue;
                if(!checkForSubBox(board,ch,i,j)){
                    return false;
                }
                if(!checkForRow(i,j,ch,board)){
                    return false;
                }
                if(!checkForCol(i,j,ch,board)){
                    return false;
                }
            }
        }
        return true;
    }
};
