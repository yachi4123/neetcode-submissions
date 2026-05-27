class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();
        vector<int>next(n,n);
        vector<int>pre(n,-1);
        stack<pair<int,int>>st;
        // next smaller element
        for(int i = n-1;i>=0;i--){
            if(st.empty()){
                next[i] = n;
                st.push({ht[i],i});
            }
            else if(ht[i]<=st.top().first){
                while(!st.empty()&&ht[i]<=st.top().first){
                    st.pop();
                }
                if(st.empty()){
                    next[i]=n;
                    st.push({ht[i],i});
                }
                else{
                    next[i] = st.top().second;
                    st.push({ht[i],i});
                }
            }
            else{
                next[i] = st.top().second;
                st.push({ht[i],i});
            }
        }
        // previous smaller element
        while(!st.empty())st.pop();
        for(int i=0;i<n;i++){
            if(st.empty()){
                pre[i] = -1;
                st.push({ht[i],i});
            }
            else if(ht[i]<=st.top().first){
                while(!st.empty()&&ht[i]<=st.top().first){
                    st.pop();
                }
                if(st.empty()){
                    pre[i]=-1;
                    st.push({ht[i],i});
                }
                else{
                    pre[i] = st.top().second;
                    st.push({ht[i],i});
                }
            }
            else{
                pre[i] = st.top().second;
                st.push({ht[i],i});
            }
        } 
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,(next[i]-pre[i]-1)*ht[i]);
        }
        return ans;
    }
};
