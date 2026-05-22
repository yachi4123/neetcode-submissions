class Solution {
public:

    void solve(int ind, vector<int>& nums,vector<vector<int>>&ans,vector<int>&v){
        int n = nums.size();
        if(ind>=n){
            ans.push_back(v);
            return;
        }
        // pick
        v.push_back(nums[ind]);
        solve(ind+1,nums,ans,v);
        // not pick
        v.pop_back();
        solve(ind+1,nums,ans,v);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(0,nums,ans,v);
        return ans;
    }
};
