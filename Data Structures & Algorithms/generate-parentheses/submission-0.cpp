class Solution {
public:

    void solve(int &n, vector<string>& ans, int i, int j, string& s){
        if(i>=n&&j>=n){
            ans.push_back(s);
            return;
        }
        if(j<i){
            if(i<n){
                s+="(";
                solve(n,ans,i+1,j,s);
                s.pop_back();
                s+=")";
                solve(n,ans,i,j+1,s);
                s.pop_back();
            }
            else{
                s+=")";
                solve(n,ans,i,j+1,s);
                s.pop_back();
            }
        }
        else{
            s+="(";
            solve(n,ans,i+1,j,s);
            s.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        int i = 0;
        int j = 0;
        vector<string>ans;
        string s = "";
        solve(n,ans,i,j,s);
        return ans;
    }
};
