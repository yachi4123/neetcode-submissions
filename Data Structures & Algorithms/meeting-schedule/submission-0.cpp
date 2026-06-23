/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int,int>>v;
        for(int i=0;i<intervals.size();i++){
            int s = intervals[i].start;
            int e = intervals[i].end;
            v.push_back({s,e});
        }
        sort(v.begin(),v.end());
        int e = 0;
        for(int i=0;i<v.size();i++){
            int s1 = v[i].first;
            int e1 = v[i].second;
            if(s1<e){
                return false;
            }
            e = e1;
        }
        return true;
    }
};
