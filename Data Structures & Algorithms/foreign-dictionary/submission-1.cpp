class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,string>adj;
        unordered_map<char,int>ind;
        int i=0;
        int j=1;
        while(j<words.size()){
            string a = words[i];
            string b = words[j];
            int len = min(a.length(),b.length());
            int k = 0;
            int check = 0;
            while(k<len){
                if(a[k]!=b[k]){
                    adj[a[k]].push_back(b[k]);
                    ind[b[k]]++;
                    check=1;
                    break;
                }
                k++;
            }
            //invalid ordering
            if(check==0&&a.length()>b.length())return {};
            i++;j++;
        }
        queue<char>q;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                if(ind.find(words[i][j])==ind.end()){
                    ind[words[i][j]]=0;
                }
            }
        }
        for(auto i:ind){
            if(i.second==0){
                q.push(i.first);
            }
        }
        // topological sorting
        string ans;
        while(!q.empty()){
            char node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto i:adj[node]){
                ind[i]--;
                if(ind[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()==ind.size())return ans;
        return "";
    }
};
