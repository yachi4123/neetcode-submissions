class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26,0);
        for(int i=0;i<tasks.size();i++){
            v[tasks[i]-'A']++;
        }
        priority_queue<int>pq;
        for(int i = 0;i<26;i++){
            if(v[i]>0){
                pq.push(v[i]);
            }
        }
        int top = pq.top();
        pq.pop();
        int id = (top-1)*n;
        int total = id+top;
        while(!pq.empty()){
            int val = pq.top();
            pq.pop();
            if(id==0){
                total+=val;
            }
            else if(val==top){
                id-=(top-1);
                total++;
            }
            else if(id>=val){
                id-=val;
            }
            else{
                val-=id;
                total+=val;
                id = 0;
            } 
        }
        return total;
    }
};
