class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int k=i;
        int j = n-1;
        while(k<=j){
            if(nums[k]==0){
                swap(nums[k],nums[i]);
                i++;k=i;
            }
            else if(nums[k]==2){
                swap(nums[k],nums[j]);
                j--;k=i;
            }
            else if(nums[k]==1){
                k++;
            }
        }
    }
};