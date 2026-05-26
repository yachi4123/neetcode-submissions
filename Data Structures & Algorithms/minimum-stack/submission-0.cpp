class MinStack {
        
    public:
    vector<int>v;
    map<int,int>mp;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
        mp[val]++;
    }
    
    void pop() {
        int val = v[v.size()-1];
        mp[val]--;
        if(mp[val]==0)mp.erase(val);
        v.pop_back();
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return mp.begin()->first;
    }
};
