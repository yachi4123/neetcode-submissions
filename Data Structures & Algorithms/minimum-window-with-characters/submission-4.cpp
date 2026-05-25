class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length())return "";
        unordered_map<char,int>mp;
        unordered_map<char,int>mp2;
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        pair<int,int>p;
        int len = INT_MAX;
        int i = 0;
        int j = 0;
        int match = 0;
        while(i<=j && j<s.length()){
            if(match == mp.size()){
                while(i<=j && match == mp.size()){
                    if(len>j-i+1){
                        len = j-i+1;
                        p = {i,j};
                    }
                    if(mp2.find(s[i])!=mp2.end()){
                        mp2[s[i]]--;
                        if(mp2[s[i]]<mp[s[i]])match--;
                    }
                    i++;
                }
                j++;
            }
            else if(mp.find(s[j])!=mp.end()){
                mp2[s[j]]++;
                if(mp2[s[j]]==mp[s[j]])match++;
                if(match!=mp.size()) j++;
            }
            else j++;
        }
        if(len==INT_MAX)return "";
        string ans;
        for(int i = p.first;i<=p.second;i++){
            ans.push_back(s[i]);
        }
        return ans;
    }
};
