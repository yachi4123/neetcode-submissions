class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int score = 0;
        int ans = -1;
        int check = 1;
        for(int i=0;i<n;i++){
            int g = gas[i];
            int c = cost[i];
            if(c>g){
                int pre = score;
                score+=(c-g);
                if(score>pre)check=1;
            }
            else{
                int v = g-c;
                score-=v;
                if(check==1){
                    ans = i;
                }
                check=0;
            }
        }
        if(score<=0)return ans;
        return -1;
    }
};
