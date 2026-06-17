class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            int val = i+nums[i];
            if(i<=maxi){
                maxi = max(maxi,val);
            }
            else return false;
        }
        return true;
    }
};
