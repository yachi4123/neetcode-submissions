class Solution {
public:
    int ladderLength(string start,
     string end, vector<string>& words) {
        words.push_back(start);
        unordered_map<string,vector<string>>adj;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                string a = words[i];
                string b = words[j];
                int diff = 0;
                int k = 0;
                while(k<a.length()){
                    if(a[k]!=b[k])diff++;
                    k++;
                }
                if(diff==1){
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                }
            }
        }
        unordered_map<string,int>dis;
        dis[start] = 1;
        queue<string>q;
        q.push(start);
        while(!q.empty()){
            string node = q.front();
            int distance = dis[node];
            q.pop();
            for(auto i : adj[node]){
                if(dis.find(i)==dis.end()){
                    dis[i]=distance+1;
                    q.push(i);
                }
                else{
                    if(dis[i]>distance+1){
                        dis[i] = distance+1;
                        q.push(i);
                    }
                }
            }
        }
        return dis[end];
    }
};
