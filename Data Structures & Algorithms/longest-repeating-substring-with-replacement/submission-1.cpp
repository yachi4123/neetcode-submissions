class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int i = 0;
        int j = 0;
        int maxi = 0;
        int tot = 0;
        int ans = 0;
        while(i<=j && j<s.length()){
            mp[s[j]]++;
            maxi = max(maxi,mp[s[j]]);
            tot++;
            if(tot-maxi<=k){
                ans = max(ans,tot);
            }
            else{
                while(i<=j){
                    mp[s[i]]--;
                    tot--;
                    for(auto l:mp){
                        maxi = max(maxi,l.second);
                    }
                    if(tot-maxi<=k){
                        ans = max(ans,tot);
                        i++;
                        break;
                    }
                    i++;
                }
            }
            j++;
        }
        ans = max(ans,tot);
        return ans;
    }
};
