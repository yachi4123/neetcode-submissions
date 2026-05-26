class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        int i = 0;
        int j = k-1;
        while(j<nums.size()){
            int val = prev(mp.end())->first;
            ans.push_back(val);
            mp[nums[i]]--;
            // remove element from map if freq is zero
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            // increase left pointer
            i++;
            // increase right pointer
            j++;
            // insert right value
            if(j<n)mp[nums[j]]++;
        }
        return ans;
    }
};
