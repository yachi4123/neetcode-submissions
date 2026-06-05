class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<points.size();i++){
            int dis = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            pq.push({dis,i});
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>>ans(k);
        for(int i=0;i<k;i++){
            ans[i] = (points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
