class MedianFinder {
    private:
    vector<int>nums;
    public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        int sz = nums.size();
        sort(nums.begin(),nums.end());
        double ans = 0;
        if(sz%2==1){
            ans = nums[sz/2];
        }
        else{
            ans = (nums[sz/2]+nums[(sz-1)/2])/2.0;
        }
        return ans;
    }
};
