class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int pro = 1;
        for(int i=0;i<n;i++){
            if(nums[i]==0)cnt++;
            else pro = pro*nums[i];
        }
        vector<int>ans(n,0);
        if(cnt>1)return ans;
        else if(cnt==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    ans[i]=pro;
                }
            }
            return ans;
        }
        else{
            for(int i=0;i<n;i++){
                ans[i]=pro/nums[i];
            }
            return ans;
        }
        return ans;  
    }
};
