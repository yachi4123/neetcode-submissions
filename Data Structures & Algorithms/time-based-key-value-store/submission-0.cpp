class TimeMap {
public:

    map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>vp = mp[key];
        int s = 0;
        int e = vp.size()-1;
        string ans = "";
        while(s<=e){
            int mid = (s+e)/2;
            if(vp[mid].first<=timestamp){
                ans = vp[mid].second;
                s=mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};
