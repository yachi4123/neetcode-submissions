class Solution {
public:

    bool check(int src, int dest, vector<vector<int>>&adj){
        queue<int>q;
        unordered_map<int,int>vis;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i:adj[node]){
                if(i==dest)return true;
                else if(vis[i]==0){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int cour, vector<vector<int>>& pre, vector<vector<int>>& qr) {
        int n = pre.size();
        vector<vector<int>>adj(cour);
        for(int i=0;i<n;i++){
            int u = pre[i][0];
            int v = pre[i][1];
            adj[u].push_back(v);
        }
        vector<bool>ans;
        for(int i=0;i<qr.size();i++){
            int u = qr[i][0];
            int v = qr[i][1];
            bool val = check (u,v,adj);
            ans.push_back(val);
        }
        return ans;
    }
};