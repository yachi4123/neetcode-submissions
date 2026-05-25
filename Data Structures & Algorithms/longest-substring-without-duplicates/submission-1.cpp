class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i<=j && j<s.length()){
            if(mp.find(s[j])==mp.end()){
                mp[s[j]] = j;
                ans = max(ans,j-i+1);
                j++;
            }
            else if(mp[s[j]]>=i){
                i = mp[s[j]]+1;
                mp[s[j]] = j;
                ans = max(ans,j-i+1);
                j++;
            }
            else{
                mp[s[j]]=j;
                ans = max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};
