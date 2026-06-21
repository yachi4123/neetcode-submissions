class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& t, vector<int>& tar) {
        bool first = false;
        bool second = false;
        bool third = false;
        for(int i=0;i<t.size();i++){
            int a = t[i][0];int b = t[i][1]; int c = t[i][2];
            if(a==tar[0] && b<=tar[1] && c<=tar[2])first = true;
            if(b==tar[1] && a<=tar[0] && c<=tar[2])second = true;
            if(c==tar[2] && b<=tar[1] && a<=tar[0])third = true;
        }
        return (first && second && third);
    }
};
