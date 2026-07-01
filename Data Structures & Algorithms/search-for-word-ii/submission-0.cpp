class Node{
    public:
    Node* child[26];
    int index;
    Node(){
        for(int i=0 ;i< 26; i++){
            child[i] = nullptr;
        }
        index = -1;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string word, int ind){
        Node* temp = root;
        for(int i=0;i<word.length();i++){
            int indi = word[i]-'a';
            if(temp->child[indi]==nullptr){
                temp->child[indi] = new Node();
            }
            temp = temp->child[indi];
        }
        temp->index = ind;
    }
};

class Solution {
public:
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    void dfs(int r, int c, vector<string>&ans, vector<vector<char>>& board, vector<string>& words, Node* temp, vector<vector<bool>>& vis){
        int n = board.size();
        int m = board[0].size();
        if(r>=n||c>=m||r<0||c<0)return;
        else if(temp->child[board[r][c]-'a']==nullptr)return;
        else{
            temp = temp->child[board[r][c]-'a'];
            vis[r][c] = true;
            if(temp->index!=-1){
                ans.push_back(words[temp->index]);
                temp->index = -1;
            }
            for(int i=0;i<4;i++){
                int nr = dr[i] + r;
                int nc = dc[i] + c;
                if(nr<n&&nc<m&&nr>=0&&nc>=0&&vis[nr][nc]==false){
                    dfs(nr,nc,ans,board,words,temp,vis);
                }
            }
            vis[r][c] = false;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* tree = new Trie();
        int n = board.size();
        int m = board[0].size();
        for(int i = 0;i<words.size();i++){
            tree->insert(words[i],i);
        }
        Node* temp = tree->root;
        vector<string>ans;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(i,j,ans,board,words,temp,vis);
            }
        }
        return ans;
    }
};
