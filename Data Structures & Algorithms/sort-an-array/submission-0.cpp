class Solution {
public:

    void mergesort(vector<int>& nums,vector<int>&v,int s,int e){
        if(s==e)return;
        int mid  = (s+e)/2;
        mergesort(nums,v,s,mid);
        mergesort(nums,v,mid+1,e);
        int i = s;
        int j = mid+1;
        int k=0;
        while(i<=mid&&j<=e){
            if(nums[i]<nums[j]){
                v[k]=nums[i];
                i++;k++;
            }
            else{
                v[k]=nums[j];
                j++;k++;
            }
        }
        while(i<=mid){
            v[k]=nums[i];
            i++;k++;
        }
        while(j<=e){
            v[k]=nums[j];
            j++;k++;
        }
        for(int i=s;i<=e;i++){
            nums[i]=v[i-s];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n);
        mergesort(nums,v,0,n-1);
        return nums;
    }
};