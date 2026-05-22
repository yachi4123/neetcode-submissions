class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int>ind(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++){
            int u = nums[i][0];
            int v = nums[i][1];
            adj[v].push_back(u);
            ind[u]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int a = q.front();
            q.pop();
            for(auto i:adj[a]){
                ind[i]--;
                if(ind[i]==0){
                    q.push(i);
                    ans.push_back(i);
                }
                else if(ind[i]<0){
                    return {};
                }
            }
        }
        for(int i=0;i<numCourses;i++){
            if(ind[i]!=0)return {};
        }
        return ans;
    }
};
