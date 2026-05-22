class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<vector<int>>v(n+1);
        for(auto i:mp){
            int a = i.first;
            int b = i.second;
            v[b].push_back(a);
        }
        vector<int>ans;
        for(int i=n;i>=1;i--){
            for(auto j:v[i]){
                if(k>0){
                    ans.push_back(j);
                    k--;
                }
                else break;
            }
        }
        return ans;

    }
};
