class Solution {
public:

    bool dfs(string src, string des, double &div, 
    map<string,vector<pair<string,double>>>&adj, map<string,int>&vis){
        
        if(vis.find(src)==vis.end())return false;
        if(vis[src]==1)return false;
        if(vis[src]==0)vis[src]=1;
        if(src==des)return true;
        
        
        for(auto i:adj[src]){
            div *= (i.second);
            if(dfs(i.first,des,div,adj,vis)){
                return true;
            }
            else{
                div /= i.second;
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
     vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>>adj;
        map<string,int>vis;
        for(int i=0;i<equations.size();i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});// string -> {{string,value}}
            adj[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
            vis[equations[i][0]]=0;
            vis[equations[i][1]]=0;
        }
        vector<double>ans;
        for(int i=0;i<queries.size();i++){
            double div=1.0;
            if(dfs(queries[i][0],queries[i][1],div,adj,vis)){
                ans.push_back(div);
            }
            else{
                ans.push_back(-1.0);
            }
            for(int i=0;i<equations.size();i++){
                vis[equations[i][0]]=0;
                vis[equations[i][1]]=0;
            }
        }
        return ans;
    }
};