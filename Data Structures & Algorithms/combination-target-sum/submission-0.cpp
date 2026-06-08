class Solution {
public:

    void solve(vector<vector<int>>& ans, vector<int>& v, vector<int>& nums, int& target, int ind, int sum){
        if(ind>=nums.size())return;
        if(sum>target){
            return;
        }
        if(sum==target){
            ans.push_back(v);
            return;
        }
        // take 
        v.push_back(nums[ind]);
        sum+=nums[ind];
        solve(ans,v,nums,target,ind,sum);
        // skip
        v.pop_back();
        sum-=nums[ind];
        solve(ans,v,nums,target,ind+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(ans,v,nums,target,0,0);
        return ans;
    }
};
