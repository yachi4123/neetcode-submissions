class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        vector<int>ans;
        int i = 0;
        while(i<n){
            // remove out of window elements
            while(!dq.empty() && dq.front()<= i-k){
                dq.pop_front();
            }
            // remove smaller elements from back
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            // insert element
            dq.push_back(i);
            // if window is of len k 
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
            i++;
        }
        return ans;
    }
};
