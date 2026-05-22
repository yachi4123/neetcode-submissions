class DSU{
    vector<int>rank;
    vector<int>parent;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUltimate(int node){
        if(parent[node]==node)return node;
        return parent[node] = findUltimate(parent[node]);
    }

    bool Union(int u, int v){
        int u_u = findUltimate(u);
        int u_v = findUltimate(v);
        if(u_u==u_v){
            return false;
        }
        else if(rank[u_u]<rank[u_v]){
            parent[u_u] = u_v;
        }
        else if(rank[u_u]>rank[u_v]){
            parent[u_v]=u_u;
        }
        else{
            parent[u_v] = u_u;
            rank[u_u]++;
        }
        return true;
    }       
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU ds(n);
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            bool val = ds.Union(u,v);
            if(val==false){
                return {u,v};
            }
        }
        return{1,1};
    }
};
