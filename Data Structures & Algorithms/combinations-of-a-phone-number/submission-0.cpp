class Solution {
public:
    unordered_map<char,string>mp;
    void solve(int ind, string& digits, vector<string>& ans, string& s){
        if(ind>=digits.length()){
            ans.push_back(s);
            return;
        }
        for(int i=0; i<mp[digits[ind]].length(); i++){
            s.push_back(mp[digits[ind]][i]);
            solve(ind+1,digits,ans,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)return {};
        mp['2'] = "abc";mp['3'] = "def";mp['4'] = "ghi";mp['5'] = "jkl";
        mp['6'] = "mno";mp['7'] = "pqrs";mp['8'] = "tuv";mp['9'] = "wxyz";
        string s = "";
        vector<string>ans;
        solve(0,digits,ans,s);
        return ans;
    }
};
