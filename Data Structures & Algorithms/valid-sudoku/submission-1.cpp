#include <cstring>
class Solution {
public:

    int sub[3][3];
    int row[9];
    int col[9];
    int brr[10];
    void checkForSub(int i,int j, vector<vector<char>>& board){
        int r = (i/3)*3;
        int c = (j/3)*3;
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(board[i][j]!='.'){
                    int a = board[i][j]-'0';
                    brr[a]++;
                }
            }
        }
        int check = 0;
        for(int i=1;i<=9;i++){
            if(brr[i]>1){
                check=1;
            }
            brr[i]=0;
        }
        if(check==1){
            sub[i/3][j/3]=0; // false;
        }
        else sub[i/3][j/3]=1; // true;
    }

    void checkForRow(int r, vector<vector<char>>& board){
        for(int j=0;j<9;j++){
            if(board[r][j]!='.'){
                int a = board[r][j]-'0';
                brr[a]++;
            }
        }
        int check = 0;
        for(int i=1;i<=9;i++){
            if(brr[i]>1){
                check=1;
            }
            brr[i]=0;
        }
        if(check==1){
            row[r] = 0;
        }
        else row[r] = 1;
    }

    void checkForCol(int c, vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][c]!='.'){
                int a = board[i][c]-'0';
                brr[a]++;
            }
        }
        int check = 0;
        for(int i=1;i<=9;i++){
            if(brr[i]>1){
                check=1;
            }
            brr[i]=0;
        }
        if(check==1){
            col[c] = 0;
        }
        else col[c] = 1;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        memset(sub,-1,sizeof(sub));
        memset(row,-1,sizeof(row));
        memset(col,-1,sizeof(col));
        memset(brr,0,sizeof(brr));

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch = board[i][j];
                if(ch!='.'){
                    //int r = (i/3)*3;
                    //int c = (j/3)*3;
                    if(sub[i/3][j/3]==-1){
                        checkForSub(i,j,board);
                    }
                    if(row[i]==-1){
                        checkForRow(i,board);
                    }
                    if(col[j]==-1){
                        checkForCol(j,board);
                    }
                    if(sub[i/3][j/3]==0||row[i]==0||col[j]==0){
                        return false;
                    }
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<sub[i][j];
            }
            cout<<endl;
        }
        return true;
    }
};
