class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = -1000000;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = max(sum+nums[i],nums[i]);
            ans = max(ans,sum);
        }
        return ans;
    }
};
