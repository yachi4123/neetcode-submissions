class Solution {
public:

    int bfs(set<string>&st, string target){
        string start = "0000";
        queue<string>q;
        map<string,bool>vis;
        map<string,int>dis;
        q.push(start);
        vis[start] = true;
        dis[start] = 0;
        while(!q.empty()){
            string s = q.front();
            int d = dis[s];
            q.pop();
            for(int i=0;i<4;i++){
                string t1;
                string t2;
                for(int j=0;j<4;j++){
                    if(i==j){
                        int a = s[j]-'0';
                        char pre = ((a-1+10)%10)+'0';
                        char succ = ((a+1+10)%10)+'0';
                        t1.push_back(pre);
                        t2.push_back(succ);
                    }
                    else{
                        t1.push_back(s[j]);
                        t2.push_back(s[j]);
                    }
                    
                }
                if(st.find(t1)==st.end()&&vis[t1]==false){
                    q.push(t1);
                    vis[t1] = true;
                    dis[t1] = d+1;
                }
                if(st.find(t2)==st.end()&&vis[t2]==false){
                    q.push(t2);
                    vis[t2] = true;
                    dis[t2] = d+1;
                }
            }
        }
        if(dis.find(target)!=dis.end()){
            return dis[target];
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();
        set<string>st;
        for(int i=0;i<n;i++){
            st.insert(deadends[i]);
        }
        if(st.find("0000")!=st.end())return -1;
        int ans = bfs(st,target);
        return ans;
    }
};