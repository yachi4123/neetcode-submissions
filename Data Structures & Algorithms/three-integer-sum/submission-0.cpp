class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int i = 0;
        while(i<n-2){
            int j = i+1;
            int k = n-1;
            int val = nums[i]*-1;
            int val2 = nums[i];
            while(j<k){
                if(val == nums[j]+nums[k]){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int val1 = nums[j];
                    while(j<k){
                        if(nums[j]==val1)j++;
                        else break;
                    }
                }
                else if(nums[j]+nums[k]>val){
                    k--;
                }
                else{
                    j++;
                }
            }
            while(i<n-2){
                if(nums[i]==val2)i++;
                else break;
            }
        }
        return ans;
    }
};
