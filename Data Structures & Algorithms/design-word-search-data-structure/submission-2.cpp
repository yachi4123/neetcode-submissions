class Node{
    public:
    Node* child[26];
    bool isEnd;
    Node(){
        for(int i=0;i<26;i++){
            child[i] = nullptr;
        }
        isEnd = false;
    }
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }

    bool dfs(string& word, int ind, Node* temp){
        if(ind >= word.length()){
            if(temp->isEnd == true) return true;
            return false;
        }
        if(word[ind]=='.'){
            for(int i=0;i<26;i++){
                if(temp->child[i]!=nullptr){
                    if(dfs(word,ind+1,temp->child[i])){
                        return true;
                    }
                }
            }
            return false;
        }
        else if(temp->child[word[ind]-'a']!=nullptr){
            return dfs(word, ind+1, temp->child[word[ind]-'a']);
        }
        else return false;
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(int i = 0;i<word.length();i++){
            int ind = word[i]-'a';
            if(temp->child[ind]==nullptr){
                temp -> child[ind] = new Node();
            }
            temp = temp -> child[ind];
        }
        temp->isEnd = true;
    }

    bool search(string word) {
        Node* temp = root;
        return dfs(word,0,temp);
    }
};
