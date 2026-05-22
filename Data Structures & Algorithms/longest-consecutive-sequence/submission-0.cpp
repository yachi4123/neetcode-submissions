class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int val = 0;
            if(st.find(nums[i]-1)==st.end()){
                int a = nums[i];
                while(st.find(a)!=st.end()){
                    val++;
                    a++;
                }
                ans = max(ans,val);
            }
        }
        return ans;
    }
};
