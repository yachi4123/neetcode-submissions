class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({pos[i],speed[i]});
        }
        sort(vp.begin(),vp.end());
        stack<pair<int,int>>st;
        st.push({target-vp[n-1].first,vp[n-1].second});
        for(int j=n-2 ; j>=0 ; j--){
            int d1 = st.top().first;
            int s1 = st.top().second;
            int d2 = target-vp[j].first;
            int s2 = vp[j].second;
            if(d2*s1 <= d1*s2){
                continue;
            }
            else{
                st.push({d2,s2});
            }
        }
        return st.size();
    }
};
