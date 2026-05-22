class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        while(s<e){
            int mid = s + (e-s)/2;
            if((e-mid)%2==0){
                if(mid-1>=0 && nums[mid-1]==nums[mid]){
                    e=mid-2;
                }
                else if(mid+1<n && nums[mid+1]==nums[mid]){
                    s=mid+2;
                }
                else{
                    return nums[mid];
                }
            }
            else{
                if(mid-1>=0 && nums[mid-1]==nums[mid]){
                    s=mid+1;
                }
                else if(mid+1<n && nums[mid+1]==nums[mid]){
                    e=mid-1;
                }
                else{
                    return nums[mid];
                }
            }
        }
        return nums[s];
    }
};