#define ll long long

class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        vector<int>dis(n,1e9);
        for(int i = 0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int p = flights[i][2];
            adj[u].push_back({v,p});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{k+2,src}});  // {price,{stops,node}}
        int ans = 1e9;
        while(!q.empty()){
            int p = q.front().first;
            int s = q.front().second.first;
            int node = q.front().second.second;
            q.pop();
            if(s<=1){
                continue;
            }
            for(auto i:adj[node]){
                int node = i.first;
                int price = i.second;
                if(price+p<dis[node]){
                    dis[node] = price+p;
                    q.push({dis[node],{s-1,node}});
                }
            }
        }
        return (dis[dst]==1e9?-1:dis[dst]);
    }
};
