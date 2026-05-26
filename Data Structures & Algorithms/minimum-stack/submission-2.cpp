class MinStack {
        
    public:
    vector<int>v;
    vector<int>pre;
    MinStack() {
        pre.push_back(2147483647);
    }
    
    void push(int val) {
        v.push_back(val);
        pre.push_back(min(pre[pre.size()-1],(val)));
    }
    
    void pop() {
        v.pop_back();
        pre.pop_back();
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return pre[pre.size()-1];
    }
};
