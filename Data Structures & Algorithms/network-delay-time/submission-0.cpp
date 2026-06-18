class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ed = times.size();
        map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<ed;i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int>dis(n+1,1e9);
        priority_queue<pair<int,int>,
        vector<pair<int,int>>, greater<pair<int,int>>>pq;
        dis[k]=0;
        pq.push({k,0}); // {node,dis}
        while(!pq.empty()){
            int node = pq.top().first;
            int t = pq.top().second;
            pq.pop();
            if(adj.find(node)!=adj.end()){
                for(auto i:adj[node]){
                    int new_node = i.first;
                    int t_req = i.second;
                    if(t_req+t<dis[new_node]){
                        dis[new_node]=t_req+t;
                        pq.push({new_node,dis[new_node]});
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9){
                return -1;
            }
        }
        int sum = *max_element(dis.begin()+1,dis.end());
        return sum;
    }
};