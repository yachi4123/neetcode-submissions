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

    static bool cmp(Interval& a , Interval& b){
        return (a.start < b.start);
    }
    int minMeetingRooms(vector<Interval>& in) {
        sort(in.begin(),in.end(),cmp);
        multiset<int>st;
        for(int i=0; i<in.size();i++){
            int s = in[i].start;
            int e = in[i].end;
            auto it = st.upper_bound(s);
            if(it!=st.begin()){
                it--;
                st.erase(it);
                st.insert(e);
            }
            else{
                st.insert(e);
            }
        }
        return st.size();
    }
};
