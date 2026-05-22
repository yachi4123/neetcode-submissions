class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int a = (mid-1>=0?nums[mid-1]:INT_MIN);
            int b = nums[mid];
            int c = (mid+1<n?nums[mid+1]:INT_MIN);
            if(b>a&&b>c)return mid;
            else if(a>c) e = mid-1;
            else if(a<c) s = mid+1;
            else e = mid-1; 
        }
        return s;
    }
};