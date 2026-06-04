class KthLargest {
private:
priority_queue<int,vector<int>,greater<int>>pq;

public:
    KthLargest(int k, vector<int>& nums) {
        //pq.push(1e9);
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int diff = pq.size()-k;
        while(diff>0){
            pq.pop();
            diff--;
        }
        while(diff<0){
            pq.push(-10000000);
            diff++;
        }
    }
    
    int add(int val) {
        pq.push(val);
        pq.pop();
        return pq.top();
    }
};
