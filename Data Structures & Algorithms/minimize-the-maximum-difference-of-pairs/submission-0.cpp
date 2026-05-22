class Solution {
public:

    bool good(vector<int>& nums, int mid, int p){
        int j=nums.size()-1;
        int i=j-1;
        while(i>=0&&j>=0){
            if(nums[j]-nums[i]<=mid){
                i-=2;
                j-=2;
                p--;
            }
            else{
                i--;j--;
            }
        }
        if(p<=0)return true;
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int min = nums[0];
        int max = nums[n-1];
        int s = 0;
        int e = max-min;
        int ans = 0;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(good(nums,mid,p)){
                e = mid-1;
                ans = mid;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};