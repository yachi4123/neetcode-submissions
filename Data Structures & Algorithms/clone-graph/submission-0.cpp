/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr)return nullptr;
        Node* root = new Node();
        root->val = node->val;
        root->neighbors = node->neighbors;
        queue<Node*>q;
        set<int>st;
        map<int,Node*>mp;
        mp[root->val] = root;
        st.insert(root->val);
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
            int sz = temp->neighbors.size();
            q.pop();
            for(int i = 0;i<sz;i++){
                Node* newnode = new Node();
                newnode->val = (temp->neighbors)[i]->val;
                newnode->neighbors = (temp->neighbors)[i]->neighbors;
                if(st.find(newnode->val)==st.end()){
                    q.push(newnode);
                    st.insert(newnode->val);
                    (temp->neighbors)[i] = newnode;
                    mp[newnode->val] = newnode;
                }
                else{
                    Node* real = mp[newnode->val];
                    (temp->neighbors)[i] = real;
                }
            }
        }
        return root;
    }
};
