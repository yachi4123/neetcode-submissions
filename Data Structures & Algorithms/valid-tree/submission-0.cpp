class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int sz = edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<sz;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        vis[0]=1;
        queue<pair<int,int>>q;
        q.push({0,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto i:adj[node]){
                if( vis[i]==1 && i!=parent)return false;
                else if(vis[i]==0){
                    vis[i]=1;
                    q.push({i,node});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0)return false;
        }
        return true;
    }
};
