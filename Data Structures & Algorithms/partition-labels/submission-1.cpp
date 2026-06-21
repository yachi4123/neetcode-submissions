class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>v(26);
        for(int i=0;i<s.length();i++){
            v[s[i]-'a'] = i;
        }
        int pre = -1;
        int last = -1;
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            last = max(last,v[s[i]-'a']);
            if(i!=last){
                continue;
            }
            else{
                ans.push_back(i-pre);
                pre = i;
                last = -1;
            }
        }
        return ans;
    }
};
