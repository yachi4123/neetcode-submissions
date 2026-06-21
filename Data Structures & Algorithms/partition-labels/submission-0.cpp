class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int pre = -1;
        set<int>st;
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            st.insert(s[i]);
            mp[s[i]]--;
            if(mp[s[i]]==0)st.erase(s[i]);
            if(st.empty()){
                ans.push_back(i-pre);
                pre = i;
            }
        }
        return ans;
    }
};
