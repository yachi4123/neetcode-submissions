class Solution {
public:

    void solve(vector<vector<int>>& ans, vector<int>& v, vector<int>& nums, int& target, int ind, int sum){
        if(sum==target){
            ans.push_back(v);
            return;
        }
        if(sum>target){
            return;
        }
        if(ind>=nums.size())return;
        // take 
        v.push_back(nums[ind]);
        sum+=nums[ind];
        solve(ans,v,nums,target,ind+1,sum);
        if(sum>target){
            v.pop_back();
            return;
        }
        // skip
        v.pop_back();
        sum-=nums[ind];
        for(int i=ind+1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                solve(ans,v,nums,target,i,sum);
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        solve(ans,v,nums,target,0,0);
        return ans;
    }
};

