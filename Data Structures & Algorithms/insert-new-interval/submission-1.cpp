class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& in) {
        vector<vector<int>>ans;
        ans.push_back(in);
        int i = 0;
        while(i<arr.size()){
            int s = arr[i][0];
            int e = arr[i][1];
            int s1 = ans[ans.size()-1][0];
            int e1 = ans[ans.size()-1][1];
            //no overlap
            if(e<s1){
                ans.pop_back();
                ans.push_back({s,e});
                ans.push_back({s1,e1});
            }
            else if(s>e1){
                ans.push_back({s,e});
            }
            // overlap
            else if(s<=e1 && s1<=e){
                ans.pop_back();
                ans.push_back({min(s,s1),max(e,e1)});
            }
            i++;
        }
        return ans;
    }
};
