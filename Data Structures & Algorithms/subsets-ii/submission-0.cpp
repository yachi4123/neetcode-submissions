class Solution {
public:

    void solve(int prev,int ind, vector<int>& nums,vector<vector<int>>&ans,vector<int>&v){
        int n = nums.size();
        if(ind>=n){
            ans.push_back(v);
            return;
        }
        
        // pick
        v.push_back(nums[ind]);
        if(prev!=nums[ind])
        solve(-100,ind+1,nums,ans,v);
        
        // not pick
        v.pop_back();
        solve(nums[ind],ind+1,nums,ans,v);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        solve(-100,0,nums,ans,v);
        return ans;
    }
};
