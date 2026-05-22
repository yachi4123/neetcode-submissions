class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        ans.push_back(v[0]);
        int n = v.size();
        for(int i=1;i<n;i++){
            int a = v[i][0];
            int b = v[i][1];
            int f = ans[ans.size()-1][0];
            int s = ans[ans.size()-1][1];
            if(a>=f&&a<=s){
                f = min(f,a);
                s = max(s,b);
                ans.pop_back();
                ans.push_back({f,s});
            }
            else{
                ans.push_back({a,b});
            } 
        }
        return ans;
    }
};
