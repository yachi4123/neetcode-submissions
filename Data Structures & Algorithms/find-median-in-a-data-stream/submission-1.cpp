class MedianFinder {
    private:
    priority_queue<int>pq1; // max-heap -> smaller elements
    priority_queue<int,vector<int>,greater<int>>pq2; // min-heap -> larger elements
    public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.empty()&&pq2.empty()){
            pq1.push(num);
            return;
        }
        if(pq1.top()>num){
            pq1.push(num);
            if(pq1.size()-pq2.size()>1){
                pq2.push(pq1.top());
                pq1.pop();
            }
        }
        else{
            pq2.push(num);
            if(pq2.size()-pq1.size()>1){
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
    }
    
    double findMedian() {
        int sz = pq1.size()+pq2.size();
        if(sz%2==1){
            if(pq1.size()>pq2.size()){
                return pq1.top();
            }
            else return pq2.top();
        }
        else{
            return (pq1.top()+pq2.top())/2.0;
        } 
    }
};
