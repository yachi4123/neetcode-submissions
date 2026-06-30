class Node {
    public:
    Node* child[26];
    bool isEnd;
    Node(){
        for(int i=0;i<26;i++){
            child[i] = nullptr;
            isEnd = false;
        }
    }
};

class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(curr->child[word[i]-'a']==nullptr){
                curr->child[word[i]-'a'] = new Node();
            }
            curr = curr->child[word[i]-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(curr->child[word[i]-'a']==nullptr){
                return false;
            }
            curr = curr->child[word[i]-'a'];
        }
        if(curr->isEnd==true)return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0;i<prefix.length();i++){
            if(curr->child[prefix[i]-'a']==nullptr){
                return false;
            }
            curr = curr->child[prefix[i]-'a'];
        }
        return true;
    }
};



