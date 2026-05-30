class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = (s+e)/2;
            // whole array sorted
            if(nums[s]<=nums[mid]&&nums[mid]<=nums[e]){
                if(nums[mid]>target){
                    e = mid-1;
                }
                else if(nums[mid]<target){
                    s = mid+1;
                }
                else{
                    return mid;
                }
            }
            // left half sorted
            else if(nums[s]<=nums[mid]){
                if(target<=nums[mid]&&target>=nums[s]){
                    e = mid;
                }
                else{
                    s = mid+1;
                }
            }
            // right half sorted
            else if(nums[mid]<=nums[e]){
                if(target>=nums[mid]&&target<=nums[e]){
                    s = mid;
                }
                else{
                    e = mid-1;
                }
            }
        }
        return -1;
    }
};
