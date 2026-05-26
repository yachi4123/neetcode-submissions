class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<pair<int,int>>st;
        vector<int>ans(n);
        st.push({temp[n-1],n-1});
        ans[n-1] = 0;
        int j = n-2;
        while(j>=0){
            while(!st.empty()){
                if(temp[j]>=st.top().first){
                    st.pop();
                }
                else{
                    ans[j] = st.top().second-j;
                    st.push({temp[j],j});
                    break;
                }
            }
            if(st.empty()){
                ans[j] = 0;
                st.push({temp[j],j});
            }
            j--;
        }
        return ans;
    }
};
