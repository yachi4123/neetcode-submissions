class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>v1(26,0);
        for(int i=0;i<s.length();i++){
            v1[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            v1[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(v1[i]!=0)return false;
        }
        return true;
        
    }
};
