class Solution {
public:

    void solve(vector<int>& nums, vector<int>& v, unordered_set<int>& st, vector<vector<int>>& ans){
        for(int i=0;i<nums.size();i++){
            if(st.find(i)==st.end()){
                st.insert(i);
                v.push_back(nums[i]);
                solve(nums,v,st,ans);
                st.erase(i);
                v.pop_back();
            }
        }
        if(v.size()==nums.size())
        ans.push_back(v);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_set<int>st;
        vector<int>v;
        solve(nums,v,st,ans);
        return ans;
    }
};
